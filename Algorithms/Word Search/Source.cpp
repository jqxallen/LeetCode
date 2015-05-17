/*
 * Author: Qiang Jia
 * Date: Nov 22, 2013
 * Link: https://leetcode.com/problems/word-search/
 * Description:
 * 		Given a 2D board and a word, find if the word exists in the grid.
 * 		The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * 		For example,
 * 			Given board =
 * 			[
 * 				["ABCE"],
 * 				["SFCS"],
 * 				["ADEE"]
 * 			]
 * 			word = "ABCCED", -> returns true,
 * 			word = "SEE", -> returns true,
 * 			word = "ABCB", -> returns false.
 */

#include <vector>
using namespace::std;

class Solution {
public:
	bool search(vector<vector<pair<char, bool>>> &board, const string &word, int i, int j, int idx) {
		if (idx == word.size()) return 1;
		/* current -> top */
		if (i > 0 && board[i - 1][j].first == word[idx] && board[i - 1][j].second) {
			board[i - 1][j].second = 0;
			if (this->search(board, word, i - 1, j, idx + 1)) return 1;
			board[i - 1][j].second = 1;
		}
		/* current -> right */
		if (j < this->col - 1 && board[i][j + 1].first == word[idx] && board[i][j + 1].second) {
			board[i][j + 1].second = 0;
			if (this->search(board, word, i, j + 1, idx + 1)) return 1;
			board[i][j + 1].second = 1;
		}
		/* current -> bottom */
		if (i < this->row - 1 && board[i + 1][j].first == word[idx] && board[i + 1][j].second) {
			board[i + 1][j].second = 0;
			if (this->search(board, word, i + 1, j, idx + 1)) return 1;
			board[i + 1][j].second = 1;
		}
		/* current -> left */
		if (j > 0 && board[i][j - 1].first == word[idx] && board[i][j - 1].second) {
			board[i][j - 1].second = 0;
			if (this->search(board, word, i, j - 1, idx + 1)) return 1;
			board[i][j - 1].second = 1;
		}
		return 0;
	}
	bool exist(vector<vector<char> > &board, string word) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (word == "") return 1;
		this->row = board.size();
		if (!this->row) return 0;
		if (this->row) this->col = board[0].size();
		if (!this->col) return 0;
		vector<vector<pair<char, bool>>> colls;
		for (int i = 0; i < this->row; ++i) {
			vector<pair<char, bool>> coll;
			for (int j = 0; j < this->col; ++j)
				coll.push_back(make_pair(board[i][j], 1));
			colls.push_back(coll);
		}
		for (int i = 0; i < this->row; ++i) {
			for (int j = 0; j < this->col; ++j) {
				if (colls[i][j].first == word[0]) {
					colls[i][j].second = 0;
					if (this->search(colls, word, i, j, 1)) return 1;
					colls[i][j].second = 1;
				}
			}
		}
		return 0;
	}
private:
	int row;
	int col;
};
