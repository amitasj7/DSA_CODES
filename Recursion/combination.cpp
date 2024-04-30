#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int n, int k, vector<vector<int>> &ans, int current, vector<int> &ansHelper)
    {
        // BASE CASE
        if (k == 0)
        {
            ans.push_back(ansHelper);
            return;
        }
        if (current > n)
        {
            return;
        }

        // LOGIC
        // 1. pick current element
        ansHelper.push_back(current);
        helper(n, k - 1, ans, current + 1, ansHelper);

        ansHelper.pop_back();

        // 2. not pick current element
        helper(n, k, ans, current + 1, ansHelper);

        // RETURN
    }
    vector<vector<int>> combine(int n, int k)
    {

        vector<vector<int>> ans;

        vector<int> ansHelper;
        helper(n, k, ans, 1, ansHelper);
        return ans;
    }
};