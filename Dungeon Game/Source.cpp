#include <iostream>
#include <vector>
#include <iterator>
using namespace::std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        vector<vector<int>>::size_type row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> dp;
        dp.resize(row, vector<int>(col));
        dp[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
        for (auto i = row - 1; i > 0; --i)
            dp[i - 1][col - 1] = max(1, dp[i][col - 1] - dungeon[i - 1][col - 1]);
        for (auto i = col - 1; i > 0; --i)
            dp[row - 1][i - 1] = max(1, dp[row - 1][i] - dungeon[row - 1][i - 1]);
        for (auto i = row - 1; i > 0; --i)
            for (auto j = col - 1; j > 0; --j)
                dp[i - 1][j - 1] = min(max(1, dp[i][j - 1] - dungeon[i - 1][j - 1]), max(1, dp[i - 1][j] - dungeon[i - 1][j - 1]));
        return dp[0][0];
    }
};

int main() {
    int arr[] = {-2, -3, 3, -5, -10, 1, 10, 30, -5};
    int cols = 3, rows = sizeof(arr) / sizeof(int) / cols;
    vector<vector<int>> dungeon;
    for (int i = 0; i < rows; ++i)
        dungeon.push_back(vector<int>(arr + i * cols, arr + (i + 1) * cols));
    Solution solution;
    cout << solution.calculateMinimumHP(dungeon) << endl;
    return 0;
}
