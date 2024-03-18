#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {

        // create a hashmap
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        int maxFreq = 0;

        // find maxFreq elements;
        for (auto it : mp)
        {

            if (it.second > maxFreq)
            {
                maxFreq = it.second;
                ans = maxFreq;
            }
            else if (it.second == maxFreq)
            {
                ans += maxFreq;
            }
        }
        return ans;
    }
};