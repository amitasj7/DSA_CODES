#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {

        int n = nums.size();
        int temp = 1;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            // increase temp
            if (nums[i] == nums[i - 1])
            {
                temp++;
            }
            // reset temp
            else
            {
                temp = 1;
            }
            if (temp >= 3)
            {
                return false;
            }
        }

        return true;
    }
};