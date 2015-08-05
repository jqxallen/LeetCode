/*
 * Author: Qiang Jia
 * Date: Aug 5, 2015
 * Link: https://leetcode.com/problems/n-queens/
 * Description:
 *      The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
 *      Given an integer n, return all distinct solutions to the n-queens puzzle.
 *      Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *      For example,
 *      	There exist two distinct solutions to the 4-queens puzzle:
 *      		[
 *      		 [".Q..",  // Solution 1
 *      		  "...Q",
 *      		  "Q...",
 *      		  "..Q."],
 *      		 ["..Q.",  // Solution 2
 *      		  "Q...",
 *      		  "...Q",
 *      		  ".Q.."]
 *      		]
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace::std;

class Solution {
public:
	bool isValid(const int i) {
		return i > -1 && i < board.size();
	}
	bool isSafe(const int i, const int j) {
		for (int k = 0; k < board.size(); ++k) {
			if (board[i][k] == 'Q' || board[k][j] == 'Q')
				return false;
			if (isValid(i - k) && isValid(j - k) && board[i - k][j - k] == 'Q')
				return false;
			if (isValid(i - k) && isValid(j + k) && board[i - k][j + k] == 'Q')
				return false;
			if (isValid(i + k) && isValid(j - k) && board[i + k][j - k] == 'Q')
				return false;
			if (isValid(i + k) && isValid(j + k) && board[i + k][j + k] == 'Q')
				return false;
		}
		return true;
	}
	void backtrack(const int k) {
		if (k < 0) {
			results.push_back(vector<string>(board));
			return;
		}
		for (int i = 0; i < board.size(); ++i) {
			if (isSafe(k, i)) {
				board[k][i] = 'Q';
				backtrack(k - 1);
				board[k][i] = '.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		for (int i = 0; i < n; ++i)
			board.push_back(string(n, '.'));
		backtrack(n - 1);
		return results;
	}
private:
	vector<string> board;
	vector<vector<string>> results;
};

void main()
{
	Solution solution;
	vector<vector<string>> results = solution.solveNQueens(4);
	for (auto it = results.cbegin(); it != results.cend(); ++it) {
		copy(it->cbegin(), it->cend(), ostream_iterator<string>(cout, "\n"));
		cout << endl;
	}
}
