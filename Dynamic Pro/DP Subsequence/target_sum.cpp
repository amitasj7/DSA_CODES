#include <bits/stdc++.h>
using namespace std;

/* 
Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1

 */
class Solution
{
public:
    int helper(int index, int target, vector<int> &nums)
    {

        // Base Case
        if (index == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        // logic

        int notPick = helper(index - 1, target, nums);

        int pick = 0;

        if (nums[index] <= target)
        {
            pick = helper(index - 1, target - nums[index], nums);
        }

        // return value
        return notPick + pick;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();

        // find total sum of nums
        int totalSum = 0;
        for (auto it : nums)
        {
            totalSum += it;
        }

        if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
        {
            return false;
        }
        int sum2 = (totalSum - target) / 2;

        int ans = helper(n - 1, sum2, nums);

        return ans;
    }
};

// tabulation

class Solution
{
public:
    int findSubsets(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // base case fill for index 0
        // index 0 par ek element hi present hoga to bas uske liye dp fill kar lege
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
        {
            dp[0][0] = 1;
        }

        if (nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1;

        for (int index = 1; index < n; index++)
        {
            for (int sum = 0; sum <= target; sum++)
            {
                // logic

                int notPick = dp[index - 1][sum];

                int pick = 0;

                if (nums[index] <= sum)
                {
                    pick = dp[index - 1][sum - nums[index]];
                }

                // return value
                dp[index][sum] = notPick + pick;
            }
        }

        int ans = dp[n - 1][target];

        return ans;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();

        // find total sum of nums
        int totalSum = 0;
        for (auto it : nums)
        {
            totalSum += it;
        }

        if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
        {
            return false;
        }
        int sum2 = (totalSum - target) / 2;

        return findSubsets(sum2, nums);
    }
};

// space optimization

class Solution
{
public:
    int findSubsets(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prev(target + 1, 0), current(target + 1, 0);

        // base case fill for index 0
        // index 0 par ek element hi present hoga to bas uske liye dp fill kar lege
        if (nums[0] == 0)
            prev[0] = 2;
        else
        {
            prev[0] = 1;
        }

        if (nums[0] != 0 && nums[0] <= target)
            prev[nums[0]] = 1;

        for (int index = 1; index < n; index++)
        {
            for (int sum = 0; sum <= target; sum++)
            {
                // logic

                int notPick = prev[sum];

                int pick = 0;

                if (nums[index] <= sum)
                {
                    pick = prev[sum - nums[index]];
                }

                // return value
                current[sum] = notPick + pick;
            }
            prev = current;
        }

        int ans = prev[target];

        return ans;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();

        // find total sum of nums
        int totalSum = 0;
        for (auto it : nums)
        {
            totalSum += it;
        }

        if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
        {
            return false;
        }
        int sum2 = (totalSum - target) / 2;

        return findSubsets(sum2, nums);
    }
};