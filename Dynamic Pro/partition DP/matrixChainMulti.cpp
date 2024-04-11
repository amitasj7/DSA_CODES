#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int helper(int i, int j, int *arr, int n)
    {

        // Base Case
        if (i == j)
            return 0;

        // logic
        int mini = 1e9;
        for (int k = i; k < j; k++)
        {

            int operations = arr[i - 1] * arr[k] * arr[j] + helper(i, k, arr, n) + helper(k + 1, j, arr, n);

            mini = min(mini, operations);
        }

        // return
        return mini;
    }
    int matrixChainMultiplication(int *arr, int n)
    {
        // Write your code here

        int ans = helper(1, n - 1, arr, n);
        return ans;
    }
};
// Memo
class Solution
{

    int helper(int i, int j, vector<vector<int>> &dp, int *arr, int n)
    {

        // Base Case
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        // logic
        int mini = 1e9;
        for (int k = i; k < j; k++)
        {

            int operations = arr[i - 1] * arr[k] * arr[j] + helper(i, k, dp, arr, n) + helper(k + 1, j, dp, arr, n);

            mini = min(mini, operations);
        }

        // return
        return dp[i][j] = mini;
    }
    int matrixChainMultiplication(int *arr, int n)
    {
        // Write your code here

        n = n + 1;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = helper(1, n - 1, dp, arr, n);
        return ans;
    }
};

// Tabulation
class Solution
{

    
    int matrixChainMultiplication(int *arr, int n)
    {
        // Write your code here

        n = n + 1;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        //  // Base Case already filll
        // if (i == j)
        //     return 0;

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i; j < n; j++)
            {

                // logic
                int mini = 1e9;
                for (int k = i; k < j; k++)
                {

                    int operations = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

                    mini = min(mini, operations);
                }

                dp[i][j] = mini;
            }
        }

        int ans = dp[1][n - 1];
        return ans;
    }
};