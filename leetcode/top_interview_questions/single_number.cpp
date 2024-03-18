#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"

/* int helper(vector<int> &nums)
{

    if (nums.size() == 1 || nums[0] != nums[1])
    {
        return nums[0];
    }
    // vector<int> result(nums.size() - 2);
    // auto start = (nums.begin() + 2);
    // auto end = nums.end();

    // cout << "value: " << nums.begin() << endl;
    // copy(start, end, result.begin());

    vector<int> subvector = {nums.begin() + 2, nums.end()};
    // PrintVec(subvector);

   return  helper(subvector);
}
int singleNumber(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    return helper(nums);
}
 */
int singleNumber(vector<int> &nums)
{

    if (nums.size() == 1)
    {
        return nums[0];
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i = i + 2)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
}
int main()
{
    vector<int> prices;

    InputVec(prices);
    // sort(prices.begin(), prices.end()); 
    // PrintVec(prices);
    cout << singleNumber(prices) << endl;

    return 0;
}