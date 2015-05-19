/*
 * Author: Qiang Jia
 * Date: Nov 14, 2013
 * Link: https://leetcode.com/problems/unique-paths/
 * Description:
 *		A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *		The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *		How many possible unique paths are there?
 *		Note:
 *			m and n will be at most 100.
 */

#include <algorithm>
using namespace::std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (m < 1 || n < 1) return 0;
		if (m > n) swap(m, n);
		n += m - 2, m--;
		long long val = 1;
		for (int i = 1; i <= m; ++i)
			val = val * (n - i + 1) / i;
		return val;
	}
};
