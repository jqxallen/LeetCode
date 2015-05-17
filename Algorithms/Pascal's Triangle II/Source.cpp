/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/pascals-triangle-ii/
 * Description:
 *		Given an index k, return the kth row of the Pascal's triangle.
 *		For example, given k = 3,
 *		Return [1,3,3,1].
 *		Note:
 *			Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v{ 1 };
		while (rowIndex--) {
			vector<int> t{ 1 };
			for (int i = 0; i < v.size() - 1; ++i)
				t.push_back(v[i] + v[i + 1]);
			t.push_back(1);
			v = t;
		}
		return v;
	}
};
