/*
 * Author: Qiang Jia
 * Date: Aug 5, 2015
 * Link: https://leetcode.com/problems/n-queens-ii/
 * Description:
 *      Follow up for N-Queens problem.
 *      Now, instead outputting board configurations, return the total number of distinct solutions.
 */

#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	bool isValid(const int i) {
		return i > -1 && i < board.size();
	}
	bool isSafe(const int i, const int j) {
		for (int k = 0; k < board.size(); ++k) {
			if (board[i][k] || board[k][j])
				return false;
			if (isValid(i - k) && isValid(j - k) && board[i - k][j - k])
				return false;
			if (isValid(i - k) && isValid(j + k) && board[i - k][j + k])
				return false;
			if (isValid(i + k) && isValid(j - k) && board[i + k][j - k])
				return false;
			if (isValid(i + k) && isValid(j + k) && board[i + k][j + k])
				return false;
		}
		return true;
	}
	void backtrack(const int k) {
		if (k < 0) {
			++result;
			return;
		}
		for (int i = 0; i < board.size(); ++i) {
			if (isSafe(k, i)) {
				board[k][i] = 1;
				backtrack(k - 1);
				board[k][i] = 0;
			}
		}
	}
	int totalNQueens(int n) {
		result = 0;
		for (int i = 0; i < n; ++i)
			board.push_back(vector<bool>(n, 0));
		backtrack(n - 1);
		return result;
	}
private:
	int result;
	vector<vector<bool>> board;
};

void main()
{
	Solution solution;
	cout << solution.totalNQueens(4) << endl;
}
