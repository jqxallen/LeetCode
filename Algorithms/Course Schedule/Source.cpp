/*
 * Author: Qiang Jia
 * Date: May 14, 2015
 * Link: https://leetcode.com/problems/course-schedule/
 * Description:
 *		There are a total of n courses you have to take, labeled from 0 to n - 1.
 *		Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *		Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *		For example:
 *			2, [[1,0]]
 *			There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 *			2, [[1,0],[0,1]]
 *			There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 *		Note:
 *			The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented (https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs).
 *		Hints:
 *			1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 *			2. Topological Sort via DFS (https://class.coursera.org/algo-003/lecture/52) - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 *			3. Topological sort could also be done via BFS (http://en.wikipedia.org/wiki/Topological_sorting#Algorithms).
 */

#include <vector>
using namespace::std;

class Solution {
public:
	bool isCycle(vector<vector<int>> &checker, int n) {
		if (!checker[n][0]) {
			checker[n][0] = 1;
			checker[n][1] = 1;
			for (int i = 2; i < checker[n].size(); ++i) {
				if (isCycle(checker, checker[n][i]) || checker[checker[n][i]][1])
					return 1;
			}
			checker[n][1] = 0;
		}
		return 0;
	}
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> checker(numCourses, vector<int>(2, 0));
		for (const auto &p : prerequisites)
			checker[p.first].push_back(p.second);
		for (int i = 0; i < numCourses; ++i) {
			if (isCycle(checker, i))
				return 0;
		}
		return 1;
	}
};