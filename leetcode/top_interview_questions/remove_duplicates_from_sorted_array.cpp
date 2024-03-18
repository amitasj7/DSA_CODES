#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"

int removeDuplicates(vector<int> &nums)

{

    // int size = nums.size();
    vector<int> helpvec;
    helpvec.push_back(nums[0]);

    int countdash = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == helpvec.back())
        {
            countdash++;
        }
        else
        {
            helpvec.push_back(nums[i]);
        }
    }

    int k = helpvec.size();

    nums.clear();

    for (int i = 0; i < helpvec.size(); i++)
    {
        nums.push_back(helpvec[i]);
    }

    return k;
}

int main()
{
    vector<int> nums;

    InputVec(nums);
    PrintVec(nums);

    int k = removeDuplicates(nums);
    cout << k << endl;
    PrintVec(nums);

    return 0;
}