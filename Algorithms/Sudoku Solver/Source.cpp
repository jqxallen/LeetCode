/*
 * Author: Qiang Jia
 * Date: Apr 19, 2015
 * Link: https://leetcode.com/problems/sudoku-solver/
 * Description:
 * 		Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 		Empty cells are indicated by the character '.'.
 * 		You may assume that there will be only one unique solution.
 */

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace::std;

void display(const vector<vector<char>> &board) {
	for (const auto &row : board) {
		copy(row.cbegin(), row.cend(), ostream_iterator<char>(cout));
		cout << endl;
	}
}

class Solution {
public:
	struct cell {
		int x, y;
		char val;
		bitset<9> digits;
		cell(int X, int Y) : val('.'), digits() {
			x = X;
			y = Y;
		};
	};
	void init(const vector<vector<char>> &board) {
		for (auto &c : cells) {
			for (int i = 0; i < n; ++i) {
				if (board[c.x][i] != '.')
					c.digits.set(board[c.x][i] - '1');
				if (board[i][c.y] != '.')
					c.digits.set(board[i][c.y] - '1');
				int x = c.x / 3 * 3 + i / 3;
				int y = c.y / 3 * 3 + i % 3;
				if (board[x][y] != '.')
					c.digits.set(board[x][y] - '1');
			}
		}
	}
	bool update(const int k, const int i) {
		cells[k].val = '1' + i;
		cells[k].digits.set(i);
		for (int j = k + 1; j < cells.size(); ++j) {
			if ((cells[j].x == cells[k].x) ||
				(cells[j].y == cells[k].y) ||
				(cells[j].x / 3 == cells[k].x / 3 && cells[j].y / 3 == cells[k].y / 3))
				cells[j].digits.set(i);
			if (cells[j].digits.all())
				return false;
		}
		return true;
	}
	bool backtrack(const int k) {
		if (k >= cells.size())
			return true;
		if (cells[k].digits.all())
			return false;
		for (int i = 0; i < n; ++i) {
			if (!cells[k].digits.test(i)) {
				vector<cell> snapshot(cells);
				if (update(k, i)) {
					if (backtrack(k + 1))
						return true;
				}
				cells = snapshot;
			}
		}
		return false;
	}
	void solveSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == '.')
					cells.push_back(cell(i, j));
			}
		}
		init(board);
		if (backtrack(0)) {
			for (const auto &c : cells)
				board[c.x][c.y] = c.val;
		}
	}
private:
	const int n = 9;
	vector<cell> cells;
};

void main()
{
	string strs[] = { "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79" };
	vector<vector<char>> board;
	for (const auto str : strs)
		board.push_back(vector<char>(str.cbegin(), str.cend()));
	Solution solution;
	solution.solveSudoku(board);
	display(board);
}
