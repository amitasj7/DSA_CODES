
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTotalHelper(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j)
    {
        if (dp[i][j] != INT16_MAX)
        {
            return dp[i][j];
        }

        int down = minTotalHelper(triangle, dp, i + 1, j);
        int diagonal = minTotalHelper(triangle, dp, i + 1, j + 1);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int totalRow = triangle.size();
        

        vector<vector<int>> dp(totalRow, vector<int>(totalRow, INT16_MAX));

        // Base case fill
        for (int i = 0; i < totalRow; i++)
        {
            dp[totalRow - 1][i] = triangle[totalRow - 1][i];
        }

        return minTotalHelper(triangle, dp, 0, 0);
    }
};