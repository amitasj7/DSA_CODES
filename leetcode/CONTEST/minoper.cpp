#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][12];

    int Helper(int col, int prevColor, vector<vector<int>> &cost)
    {
        if (col < 0)
            return 0;
        if (dp[col][prevColor] != -1)
            return dp[col][prevColor];

        int minCost = 2e9;
        for (int color = 0; color < 10; color++)
        {
            if (color != prevColor)
            {
                minCost = min(minCost, cost[col][color] + Helper(col - 1, color, cost));
            }
        }
        return dp[col][prevColor] = minCost;
    }

    int minimumOperations(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));

        int totalRow = grid.size(), totalCol = grid[0].size();
        vector<vector<int>> hack(totalCol, vector<int>(11, 0));

        for (int col = 0; col < totalCol; col++)
        {
            for (int color = 0; color < 10; color++)
            {
                for (int row = 0; row < totalRow; row++)
                {
                    hack[col][color] += grid[row][col] != color;
                }
            }
        }
        int ans = Helper(totalCol - 1, 10, hack);

        return ans;
    }
};

class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::vector<int>> ops(cols + 1, std::vector<int>(10, INT_MAX));

        for (int i = 0; i < 10; i++)
        {
            ops[0][i] = 0;
        }

        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                int totalOps = 0;

                for (int i = 0; i < rows; i++)
                {
                    if (grid[i][j] != k)
                    {
                        totalOps++;
                    }
                }

                for (int l = 0; l <= 9; l++)
                {
                    if (k != l)
                    {
                        ops[j + 1][k] = std::min(ops[j + 1][k], ops[j][l] + totalOps);
                    }
                }
            }
        }

        int res = INT_MAX;
        for (int k = 0; k <= 9; k++)
        {
            res = std::min(res, ops[cols][k]);
        }

        return res == INT_MAX ? -1 : res;
    }
};
class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int ans = 0;
        int totalRow = grid.size();
        int totalCol = grid[0].size();

        // Traverse the matrix from bottom to top
        for (int i = totalRow - 2; i >= 0; i--)
        {
            for (int j = 0; j < totalCol; j++)
            {
                // Make grid[i][j] equal to grid[i + 1][j]
                if (j < totalCol - 1 && grid[i + 1][j] == grid[i][j + 1])
                {
                    if (grid[i][j] != grid[i + 1][j])
                    {
                        grid[i + 1][j] = grid[i][j];

                        ans++;
                    }
                    grid[i][j + 1] = grid[i + 1][j + 1];
                    ans++;
                }
                else
                {
                    if (grid[i][j] != grid[i + 1][j])
                    {
                        grid[i][j] = grid[i + 1][j];
                        ans++;
                    }

                    // Ensure grid[i][j] is different from grid[i][j + 1]
                    if (j < totalCol - 1 && grid[i][j] == grid[i][j + 1])
                    {
                        grid[i][j]++;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
