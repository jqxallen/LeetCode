/*
 * Author: Qiang Jia
 * Date: Nov 6, 2013
 * Link: https://leetcode.com/problems/subsets/
 * Description:
 *		Given a set of distinct integers, nums, return all possible subsets.
 *		Note:
 *			Elements in a subset must be in non-descending order.
 *			The solution set must not contain duplicate subsets.
 *		For example,
 *			If nums = [1,2,3], a solution is:
 *			[
 *				  [3],
 *				  [1],
 *				  [2],
 *				  [1,2,3],
 *				  [1,3],
 *				  [2,3],
 *				  [1,2],
 *				  []
 *			]
 */

#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	void find_subsets(vector<vector<int>> &colls, const vector<int> &S) {
		for (int ele : S) {
			int size = colls.size();
			for (int i = 0; i < size; ++i) {
				vector<int> coll(colls[i]);
				coll.push_back(ele);
				sort(coll.begin(), coll.end());
				colls.push_back(coll);
			}
		}
	}
	vector<vector<int> > subsets(vector<int> &S) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<int> empty;
		vector<vector<int>> colls;
		colls.push_back(empty);
		this->find_subsets(colls, S);
		return colls;
	}
};
