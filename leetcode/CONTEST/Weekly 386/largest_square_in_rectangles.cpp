
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long squareArea(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)
    {
        if (a2 >= a1 && a2 < c1)
        {
            if (b2 >= b1 && b2 < d1)
            {
                // can form a square
                long long len = min(abs(a2 - c1), abs(b2 - d1));
                return len * len;
            }
            else if (d2 <= d1 && d2 > b1)
            {
                long long len = min(abs(a2 - c1), abs(d2 - b2));
                return len * len;
            }
        }
        return 0;
    }

    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        int size = bottomLeft.size();
        long long maxSqArea = 0;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int x2 = min(topRight[i][0], topRight[j][0]);
                int y2 = min(topRight[i][1], topRight[j][1]);

                if (x1 < x2 && y1 < y2)
                {
                    int side = min(x2 - x1, y2 - y1);
                    maxSqArea = max(maxSqArea, 1ll * side * side);
                }
            }
        }
        return maxSqArea;
    }
};
