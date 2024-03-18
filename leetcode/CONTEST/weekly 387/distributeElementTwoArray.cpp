#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {

        vector<int> v1, v2;

        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        int i = 2;

        while (i < nums.size())
        {
            int value = nums[i];

            if (v1.back() >= v2.back())
            {
                v1.push_back(value);
            }
            else
            {
                v2.push_back(value);
            }

            i++;
        }

        int sizeofV2 = v2.size();
        for (int i = 0; i < sizeofV2; i++)
        {
            v1.push_back(v2[i]);
        }

        return v1;
    }
};