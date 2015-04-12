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

int main() {
    char arr[] = {'1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1', '1'};
    vector<vector<char>> grid;
    int col = 5, row = sizeof(arr) / sizeof (char) / col;
    for (int i = 0; i < row; ++i)
        grid.push_back(vector<char>(arr + i * col, arr + (i + 1) * col));
    Solution solution;
    cout << solution.numIslands(grid) << endl;
}
