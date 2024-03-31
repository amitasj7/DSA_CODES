#include <bits/stdc++.h>
using namespace std;

// using recursion
class Solution
{
public:
    int uniquePathsHelper(int i, int j)
    {
        // Base case
        if (i < 0 || j < 0)
            return 0;
        if (i == 0 && j == 0)
        {
            return 1;
        }

        // recursion call
        int left = uniquePathsHelper(i, j - 1);
        int up = uniquePathsHelper(i - 1, j);

        // operation perfome and return
        return left + up;
    }

    int uniquePaths(int m, int n)
    {

        int i = m - 1;
        int j = n - 1;

        return uniquePathsHelper(i, j);
    }
};

// using Memoization
class Solution
{
public:
    int uniquePathsHelper(int i, int j, vector<vector<int>> &dp)
    {
        // Base case
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // recursion call
        int left = uniquePathsHelper(i, j - 1, dp);
        int up = uniquePathsHelper(i - 1, j, dp);

        // operation perfome and return
        return dp[i][j] = left + up;
    }

    int uniquePaths(int m, int n)
    {

        int i = m - 1;
        int j = n - 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        return uniquePathsHelper(i, j, dp);
    }
};

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        int i = 0;
        int j = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        set<int> s;

        while (i < nums1.size() && j < nums2.size())
        {

            if (nums1[i] == nums2[j])
            {
                s.insert(nums1[i]);
                i++;
                j++; 

            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        vector<int> ans(s.begin(), s.end());

        return ans;
    }
};