/*
 * Author: Qiang Jia
 * Date: Apr 12, 2015
 * Link: https://leetcode.com/problems/number-of-islands/
 * Description:
 *      Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *      Example 1:
 *          11110
 *          11010
 *          11000
 *          00000
 *              Answer: 1
 *          Example 2:
 *          11000
 *          11000
 *          00100
 *          00011
 *              Answer: 3
 */

#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
	int numIslands(vector<vector<char>> &grid) {
		int numOfIslands = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == '1') {
					this->dfs(grid, i, j);
					++numOfIslands;
				}
			}
		}
		return numOfIslands;
	}
	void dfs(vector<vector<char>> &grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
			return;
		grid[i][j] = '*';
		this->dfs(grid, i - 1, j);
		this->dfs(grid, i, j + 1);
		this->dfs(grid, i + 1, j);
		this->dfs(grid, i, j - 1);
	}
};

void main() {
	char arr[] = { '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1', '1' };
	vector<vector<char>> grid;
	int col = 5, row = sizeof(arr) / sizeof (char) / col;
	for (int i = 0; i < row; ++i)
		grid.push_back(vector<char>(arr + i * col, arr + (i + 1) * col));
	Solution solution;
	cout << solution.numIslands(grid) << endl;
}
