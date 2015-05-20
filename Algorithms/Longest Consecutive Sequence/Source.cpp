/*
 * Author: Qiang Jia
 * Date: Nov 21, 2013
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 * Description:
 *		Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *		For example,
 *			Given [100, 4, 200, 1, 3, 2],
 *			The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *			Your algorithm should run in O(n) complexity.
 */

#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace::std;

class Solution {
public:
	int find_consecutive(set<int> &coll, int n, bool asc) {
		int dist = 0;
		set<int>::iterator it;
		while ((it = coll.find(n)) != coll.cend())
			coll.erase(it), dist++, n += asc ? 1 : -1;
		return dist;
	}
	int longestConsecutive(vector<int> &num) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!num.size()) return 0;
		set<int> coll;
		copy(num.cbegin(), num.cend(), inserter(coll, coll.begin()));
		int dist = 0;
		for (int n : num)
			dist = max(this->find_consecutive(coll, n, 0) + this->find_consecutive(coll, n + 1, 1), dist);
		return dist;
	}
};
