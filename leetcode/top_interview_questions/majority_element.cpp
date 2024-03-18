#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"

int majorityElement(vector<int> &nums)
{
    // sort nums vector
    sort(nums.begin(), nums.end());

    // previous_count and present_count update
    pair<int, int> previous_count = {0, 0};
    int present_count = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((i+1)!= nums.size()&& nums[i] == nums[i + 1])
        {
            ++present_count;
        }
        else
        {
            if (present_count > previous_count.first)
            {
                previous_count.first = present_count;
                previous_count.second = nums[i];
            }
            present_count = 1;
        }
    }

    // return previous_count
    // cout << "no. of repitition: " << previous_count.first << endl;
    return previous_count.second;
}
int main()
{

    vector<int> nums;

    InputVec(nums);
    cout << majorityElement(nums) << endl;

    return 0;
}