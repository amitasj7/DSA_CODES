#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        int totalCount = 0;

        vector<vector<int>> prefixSumGrid(totalRow + 1, vector<int>(totalCol + 1, 0));

        for (int i = 1; i <= totalRow; ++i)
        {
            for (int j = 1; j <= totalCol; ++j)
            {
                prefixSumGrid[i][j] = grid[i - 1][j - 1] + prefixSumGrid[i - 1][j] + prefixSumGrid[i][j - 1] - prefixSumGrid[i - 1][j - 1];
            }
        }

        for (int x = 1; x <= totalRow; x++)
        {
            for (int y = 1; y <= totalCol; y++)
            {
                int totalSum = prefixSumGrid[x][y];
                if (totalSum <= k)
                {
                    totalCount += 1;
                }
            }
        }

        return totalCount;
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<vector<int>> grid = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int k = 2;
    int result = sol.countSubmatrices(grid, k);

    cout << "Result: " << result << endl;

    return 0;
}
