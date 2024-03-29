#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution
{
public:
    void helper(int index, vector<vector<int>> &ans, vector<int> &nums, int n)
    {

        //  Base Case
        if (index == n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {

            swap(nums[index], nums[i]);

            helper(index + 1, ans, nums, n);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;

        // vector<int> ansHelper;

        int n = nums.size();
        helper(0, ans, nums, n);

        return ans;
    }
};