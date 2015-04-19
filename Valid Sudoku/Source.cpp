#include <iostream>
#include <vector>
#include <string>
using namespace::std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		const int m = 3;
		const int n = m  * m;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				vector<int> checker(n, 0);
				for (int k = 0; k < m; ++k) {
					for (int l = 0; l < m; ++l) {
						if (board[i * m + k][j * m + l] != '.') {
							if (checker[board[i * m + k][j * m + l] - '1'] == 1)
								return 0;
							++checker[board[i * m + k][j * m + l] - '1'];
						}
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			vector<int> checker1(n, 0);
			vector<int> checker2(n, 0);
			for (int j = 0; j < n; ++j) {
				if (board[i][j] != '.') {
					if (checker1[board[i][j] - '1'] == 1)
						return 0;
					++checker1[board[i][j] - '1'];
				}
				if (board[j][i] != '.') {
					if (checker2[board[j][i] - '1'] == 1)
						return 0;
					++checker2[board[j][i] - '1'];
				}
			}
		}
		return 1;
	}
};

int main()
{
	string arr[] = { "..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.." };
	vector<vector<char>> board;
	for (const auto s : arr) {
		vector<char> v;
		copy(s.cbegin(), s.cend(), back_inserter(v));
		board.push_back(v);
	}
	for (const auto &v : board) {
		copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout));
		cout << endl;
	}
	Solution solution;
	cout << solution.isValidSudoku(board) << endl;
}
