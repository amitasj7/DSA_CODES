#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        int operations = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < k)
            {
                operations++;
            }
        }

        return operations;
    }
};