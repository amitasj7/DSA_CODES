#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atmostgoal(vector<int> &nums, int goal)
    {
        int count = 0;

        int start = 0;
        int sum = 0;

        for (int end = 0; end < nums.size(); end++)
        {
            // fin sum

            sum += nums[end];

            // if sum goal se jyada ho gya to window ko chhota kr dege
            while (sum > goal && start <= end)
            {

                sum -= nums[start];

                start++;
            }

            count += (end - start + 1);
        }

        return count;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        // Sliding Window Technique

        return atmostgoal(nums, goal) - atmostgoal(nums, goal - 1);
    }
};
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // Prefix Sum Concept

        unordered_map<int, int> mp;
        // <PrefixSum , count>

        // mp[0] = 1;
        int prefixSum = 0;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            if (prefixSum == goal)
                ans++;

            ans += mp[prefixSum - goal];

            mp[prefixSum]++;
        }

        return ans;
    }
};