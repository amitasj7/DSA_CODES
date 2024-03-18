#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"
/*
void moveZeroes(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    // PrintVec(nums);
    int size = nums.size();
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (nums[i] == 0)
        {
            nums.emplace_back(0);
            // PrintVec(nums);
        }
        else
        {

            break;
        }
    }
    nums.erase(nums.begin(), nums.begin() + i);
}
 */
void moveZeroes(vector<int> &nums)
{
    int size = nums.size();
    int i=0;
    while (size--)
    {
        if (nums[i] == 0)
        {
            nums.emplace_back(0);
            nums.erase(nums.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    vector<int> nums;

    InputVec(nums);
    // nums.erase();

    moveZeroes(nums);

    PrintVec(nums);
    return 0;
}