#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {

        long long ans = 0;

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vector<int> vec(2001, 0);

        // traverse whole grid
        // fill vector accordingly row and col
        for (int i = 0; i < totalRow; i++)
        {

            int rowOne = 0;

            for (int j = 0; j < totalCol; j++)
            {

                if (grid[i][j] == 1)
                {
                    rowOne += 1;
                }
            }
            vec[i] = rowOne;
        }

        // fill vector accordingly row and col
        for (int j = 0; j < totalCol; j++)
        {
            int colOne = 0;
            for (int i = 0; i < totalRow; i++)
            {

                if (grid[i][j] == 1)
                    colOne += 1;
            }
            int index = j + 1000;
            vec[index] = colOne;
        }

        for (int i = 0; i < totalRow; i++)
        {

            for (int j = 0; j < totalCol; j++)
            {
                if (grid[i][j] == 1)
                {

                    int rowOne = vec[i];
                    int colOne = vec[j + 1000];

                    ans += (rowOne - 1) * (colOne - 1);
                }
            }
        }

        return ans;
    }
};
class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {

        long long ans = 0;

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        // traverse whole grid
        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {

                // find 1
                if (grid[i][j] == 1)
                {
                    // find row and col one value
                    int rowOne = 0;
                    int colOne = 0;

                    for (int col = 0; col < totalCol; col++)
                    {
                        if (grid[i][col] == 1)
                            colOne++;
                    }
                    colOne -= 1;
                    for (int row = 0; row < totalRow; row++)
                    {
                        if (grid[row][j] == 1)
                            rowOne++;
                    }
                    rowOne -= 1;
                    if (colOne != 0 && rowOne != 0)
                        ans += rowOne * colOne;
                }
            }
        }

        return ans;
    }
};