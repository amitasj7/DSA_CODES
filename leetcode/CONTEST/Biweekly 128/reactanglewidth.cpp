#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
    {
        sort(points.begin(), points.end());

        int ans = 0;
        int left = 0, right = 0;
        left = points[0][0];

        for (int i = 0; i < points.size(); i++)
        {

            if (abs(left - points[i][0]) <= w)
            {
                right = i;

                continue;
            }
            else
            {
                ans++;

                left = points[i][0];
                right = left;
            }
        }
        ans++;

        return ans;
    }
};