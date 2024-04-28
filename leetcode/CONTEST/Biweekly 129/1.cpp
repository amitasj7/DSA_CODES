#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        int width = 0, b = 0;
        if (grid[0][0] == 'W')
            width++;
        else
            b++;
        if (grid[0][1] == 'W')
            width++;
        else
            b++;
        if (grid[1][0] == 'W')
            width++;
        else
            b++;
        if (grid[1][1] == 'W')
            width++;
        else
            b++;
        if (width == 4 || width == 3 || width == 1 || width == 0)
            return true;

        width = 0;
        b = 0;
        if (grid[0][1] == 'W')
            width++;
        else
            b++;
        if (grid[0][2] == 'W')
            width++;
        else
            b++;
        if (grid[1][1] == 'W')
            width++;
        else
            b++;
        if (grid[1][2] == 'W')
            width++;
        else
            b++;
        if (width == 4 || width == 3 || width == 1 || width == 0)
            return true;

        width = 0;
        b = 0;
        if (grid[1][0] == 'W')
            width++;
        else
            b++;
        if (grid[1][1] == 'W')
            width++;
        else
            b++;
        if (grid[2][0] == 'W')
            width++;
        else
            b++;
        if (grid[2][1] == 'W')
            width++;
        else
            b++;
        if (width == 4 || width == 3 || width == 1 || width == 0)
            return true;

        width = 0;
        b = 0;
        if (grid[1][1] == 'W')
            width++;
        else
            b++;
        if (grid[1][2] == 'W')
            width++;
        else
            b++;
        if (grid[2][1] == 'W')
            width++;
        else
            b++;
        if (grid[2][2] == 'W')
            width++;
        else
            b++;
        if (width == 4 || width == 3 || width == 1 || width == 0)
            return true;

        return false;
    }
};