#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper1(int index, int target, vector<int> &nums)
    {

        // Base Case

        if (target == 0)
            return true;

        if (index == 0)
            return nums[0] == target;

        bool notPick = helper1(index - 1, target, nums);

        // agar Element target se bda hua to pick nahi krna hai so initially hi pick me false de dege
        bool pick = false;

        if (nums[index] <= target)
        {
            pick = helper1(index - 1, target - nums[index], nums);
        }
        return pick || notPick;
    }

    bool helper(int index, int target, vector<vector<int>> &dp, vector<int> &nums)
    {

        // Base Case

        if (target == 0)
            return true;

        if (index == 0)
            return nums[0] == target;

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool notPick = helper(index - 1, target, dp, nums);

        // agar Element target se bda hua to pick nahi krna hai so initially hi pick me false de dege
        bool pick = false;

        if (nums[index] <= target)
        {
            pick = helper(index - 1, target - nums[index], dp, nums);
        }
        return dp[index][target] = pick || notPick;
    }
    bool canPartition(vector<int> &nums)
    {

        // find total Sum

        int totalSum = 0;

        for (auto it : nums)
        {
            totalSum += it;
        }

        // Even - > check for taget =  totalSum/2 ;
        if (totalSum % 2 == 0)
        {
            int target = totalSum / 2;
            int n = nums.size();

            // take a 2D DP
            vector<vector<int>> dp(n, vector<int>(target + 1, -1));

            return helper(n - 1, target, dp, nums);
        }
        return false;
    }
};