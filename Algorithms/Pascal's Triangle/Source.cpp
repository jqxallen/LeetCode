/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/pascals-triangle/
 * Description:
 * 		Given numRows, generate the first numRows of Pascal's triangle.
 * 		For example, given numRows = 5,
 * 		Return
 *			[
 *			     [1],
 *			    [1,1],
 *			   [1,2,1],
 *			  [1,3,3,1],
 *			 [1,4,6,4,1]
 *			]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> v;
		if (numRows < 1)
			return v;
		v.push_back(vector<int>(1, 1));
		while (--numRows) {
			vector<int> t(1, 1);
			for (int i = 0; i < v.back().size() - 1; ++i)
				t.push_back(v.back()[i] + v.back()[i + 1]);
			t.push_back(1);
			v.push_back(t);
		}
		return v;
	}
};
