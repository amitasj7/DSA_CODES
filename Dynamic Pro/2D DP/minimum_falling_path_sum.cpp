
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {

        if (i < 0 || j < 0 || j >= dp[0].size())
        {
            return INT_MAX;
        }

        if (dp[i][j] != INT_MAX)
        {
            return dp[i][j];
        }

        int ld = Helper(matrix, dp, i - 1, j - 1);
        int up = Helper(matrix, dp, i - 1, j);

        int rd = Helper(matrix, dp, i - 1, j + 1);

        return dp[i][j] = matrix[i][j] + min(up, min(ld, rd));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();

        int minSum = INT_MAX;
        vector<vector<int>> dp(totalRow, vector<int>(totalCol, INT_MAX));

        // fill first row of dp
        for (int j = 0; j < totalCol; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        // find all last Row min Sum value
        for (int j = 0; j < totalCol; j++)
        {

            int sum = Helper(matrix, dp, totalRow - 1, j);

            minSum = min(minSum, sum);
        }

        return minSum;
    }
};