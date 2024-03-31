#include <bits/stdc++.h>
using namespace std;

// using memorization
class Solution
{
public:
    int minPathSumHelper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = minPathSumHelper(grid, dp, i - 1, j);
        int left = minPathSumHelper(grid, dp, i, j - 1);

        return dp[i][j] = min(up, left) + grid[i][j];
    }
    int minPathSum(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vector<vector<int>> dp(totalRow, vector<int>(totalCol, -1));
        dp[0][0] = grid[0][0];

        return minPathSumHelper(grid, dp, totalRow - 1, totalCol - 1);
    }
};