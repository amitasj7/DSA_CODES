#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> ans;

        //   merge  newInterval in intervals
        intervals.push_back(newInterval);

        // sort intervals
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (auto it : intervals)
        {
            // update start and end
            if (it[0] != start && it[0] > end)
            {

                ans.push_back({start, end});
                // update start and end
                start = it[0];
                end = it[1];
            }
            else
            {
                // update end
                end = max(end, it[1]);
            }
        }

        ans.push_back({start, end}); // for last intervals

        return ans;
    }
};