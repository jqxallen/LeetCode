/*
 * Author: Qiang Jia
 * Date: Nov 22, 2013
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 * Description:
 *		Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *		Integers in each row are sorted from left to right.
 *		The first integer of each row is greater than the last integer of the previous row.
 *		For example,
 *			Consider the following matrix:
 *			[
 *			  [1,   3,  5,  7],
 *			  [10, 11, 16, 20],
 *			  [23, 30, 34, 50]
 *			]
 *			Given target = 3, return true.
 */

#include <vector>
using namespace::std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int row = matrix.size();
		if (!row) return 0;
		int col = matrix[0].size();
		if (!col) return 0;
		int i = 0, j = col - 1;
		while (i < row && j > -1) {
			if (matrix[i][j] > target) j--;
			else if (matrix[i][j] < target) i++;
			else return 1;
		}
		return 0;
	}
};
