/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/set-matrix-zeroes/
 * Description:
 *		Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *		Follow up:
 *			Did you use extra space?
 *			A straight forward solution using O(mn) space is probably a bad idea.
 *			A simple improvement uses O(m + n) space, but still not the best solution.
 *			Could you devise a constant space solution?
 */

#include <vector>
using namespace::std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int row = matrix.size();
		if (!row) return;
		int col = matrix.front().size();
		if (!col) return;
		/* check whether to clear first row and first col */
		bool clear_row = 0, clear_col = 0;
		for (int i = 0; i < col; ++i) {
			if (!matrix[0][i]) {
				clear_row = 1;
				break;
			}
		}
		for (int i = 0; i < row; ++i) {
			if (!matrix[i][0]) {
				clear_col = 1;
				break;
			}
		}
		/* set the corresponding flag to zero */
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				if (!matrix[i][j])
					matrix[0][j] = matrix[i][0] = 0;
			}
		}
		/* clear the corresponding element to zero */
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				if (!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
			}
		}
		/* clear first row and first col to zero if necessary */
		if (clear_row) {
			for (int i = 0; i < col; ++i)
				matrix[0][i] = 0;
		}
		if (clear_col) {
			for (int i = 0; i < row; ++i)
				matrix[i][0] = 0;
		}
	}
};
