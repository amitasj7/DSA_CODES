#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}
int main()
{

    vector<int> nums;

    InputVec(nums);
    cout << ((containsDuplicate(nums)) ? "True" : "False") << endl;

    return 0;
}