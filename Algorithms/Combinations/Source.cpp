/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/combinations/
 * Description:
 *		Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *		For example,
 *			If n = 4 and k = 2, a solution is:
 *			[
 *			  [2,4],
 *			  [3,4],
 *			  [2,3],
 *			  [1,2],
 *			  [1,3],
 *			  [1,4],
 *			]
 */

#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	void find_combination(vector<vector<int>> &colls, vector<int> &coll, int begin, int end, int k) {
		for (int i = begin; i <= end; ++i) {
			coll.push_back(i);
			if (k == 1) {
				vector<int> temp_coll(coll);
				colls.push_back(temp_coll);
			}
			else {
				this->find_combination(colls, coll, i + 1, end, k - 1);
			}
			coll.pop_back();
		}
	}
	vector<vector<int> > combine(int n, int k) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<vector<int>> colls;
		if (n < 1 || k < 1) return colls;
		vector<int> coll;
		this->find_combination(colls, coll, 1, n, k);
		return colls;
	}
};

void main()
{
	Solution solution;
	for (const vector<int> &coll : solution.combine(4, 2)) {
		copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
