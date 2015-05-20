/*
 * Author: Qiang Jia
 * Date: Nov 23, 2013
 * Link: https://leetcode.com/problems/rotate-image/
 * Description:
 *		You are given an n x n 2D matrix representing an image.
 *		Rotate the image by 90 degrees (clockwise).
 *		Follow up:
 *			Could you do this in-place?
 */

#include <vector>
using namespace::std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int N = matrix.size(), val;
		for (int i = 0; i < N / 2; ++i) {
			for (int j = i; j < N - 1 - i; ++j) {
				val = matrix[i][j];
				matrix[i][j] = matrix[N - 1 - j][i];
				matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
				matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
				matrix[j][N - 1 - i] = val;
			}
		}
	}
};
