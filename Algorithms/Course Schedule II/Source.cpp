/*
 * Author: Qiang Jia
 * Date: May 17, 2015
 * Link: https://leetcode.com/problems/course-schedule-ii/
 * Description:
 * 		There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 		Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 * 		Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 * 		There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 *		For example:
 *			2, [[1,0]]
 *			There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 *			4, [[1,0],[2,0],[3,1],[3,2]]
 *			There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 *		Note:
 *			The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented (https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs).
 *		Hints:
 *			1. This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 *			2. Topological Sort via DFS (https://class.coursera.org/algo-003/lecture/52) - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 *			3. Topological sort could also be done via BFS (http://en.wikipedia.org/wiki/Topological_sorting#Algorithms).
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> constraints1(numCourses, unordered_set<int>());
		vector<unordered_set<int>> constraints2(numCourses, unordered_set<int>());
		for (const auto &p : prerequisites) {
			constraints1[p.first].insert(p.second);
			constraints2[p.second].insert(p.first);
		}
		deque<int> seq;
		for (int i = 0; i < numCourses; ++i) {
			if (constraints1[i].empty())
				seq.push_back(i);
		}
		vector<int> order;
		while (!seq.empty()) {
			order.push_back(seq.front());
			for (const int i : constraints2[seq.front()]) {
				constraints1[i].erase(seq.front());
				if (constraints1[i].empty())
					seq.push_back(i);
			}
			constraints2[seq.front()].clear();
			seq.pop_front();
		}
		return order.size() != numCourses ? vector<int>() : order;
	}
};

void main()
{
	int numCourses = 10;
	vector<pair<int, int>> prerequisites({ { 5, 8 }, { 3, 5 }, { 1, 9 }, { 4, 5 }, { 0, 2 }, { 1, 9 }, { 7, 8 }, { 4, 9 } });
	Solution solution;
	vector<int> order = solution.findOrder(numCourses, prerequisites);
	copy(order.cbegin(), order.cend(), ostream_iterator<int>(cout));
}
