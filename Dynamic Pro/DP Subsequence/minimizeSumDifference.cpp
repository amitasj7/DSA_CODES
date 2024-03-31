#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {

        int mini = 1e9;

        // find nums totalSum
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }

        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= totalSum)
            dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= totalSum; target++)
            {
                bool notTake = dp[ind - 1][target];

                bool take = false;
                if (nums[ind] <= target)
                    take = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = take | notTake;
            }
        }

        for (int s1 = 0; s1 <= totalSum / 2; s1++)
        {
            if (dp[n - 1][s1] == true)
            {
                int s2 = totalSum - s1;

                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
};