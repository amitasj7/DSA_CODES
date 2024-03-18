#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"

int missingNumber(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums[i])
        {
            return i;
        }
    }
}
int main()
{
    vector<int> nums;

    InputVec(nums);
    cout << missingNumber(nums) << endl;

    return 0;
}