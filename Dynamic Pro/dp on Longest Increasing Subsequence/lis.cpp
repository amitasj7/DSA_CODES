#include <bits/stdc++.h>
using namespace std;

/*
 Example 1:

Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 0;

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (nums[prev] < nums[current] && nums[current] - nums[prev] <= k && 1 + dp[prev] > dp[current])
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                }
            }

            if (ans < dp[current])
            {
                ans = dp[current];
            }
        }

        return ans;
    }
};
/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        int ans = 1;

        for (int current = 1; current < n; current++)
        {
            // fill current element longest incresing subsequence

            if (temp.back() < nums[current])
            {
                // push into temp
                temp.push_back(nums[current]);
                ans++;
            }
            else
            {
                // replace element
                int index = lower_bound(temp.begin(), temp.end(), nums[current]) - temp.begin();
                temp[index] = nums[current];
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 0;

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (nums[prev] < nums[current] && 1 + dp[prev] > dp[current])
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                }
            }

            if (ans < dp[current])
            {
                ans = dp[current];
            }
        }

        return ans;
    }
};