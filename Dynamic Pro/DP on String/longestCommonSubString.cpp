#include <bits/stdc++.h>
using namespace std;

/*
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”
Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.
 */

// for length 3 --

int lcsubstring(string &str1, string &str2)
{
    // Write your code here.
    int ans = 0;
    int n1 = str1.size();
    int n2 = str2.size();

    // shifting index
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Base Case fill index by 0
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n2; j++)
    {
        dp[0][j] = 0;
    }

    // logic
    for (int index1 = 1; index1 <= n1; index1++)
    {
        for (int index2 = 1; index2 <= n2; index2++)
        {
            // string ko access krte time index ko shift krna hoga
            if (str1[index1 - 1] == str2[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];

                ans = max(ans, dp[index1][index2]);
            }

            else
            {
                dp[index1][index2] = 0;
            }
        }
    }

    return ans;
}

// for string "cjk"
string lcsubstring2(string &str1, string &str2)
{
    // Write your code here.
    int point = 0;
    int ans = 0;
    int n1 = str1.size();
    int n2 = str2.size();

    // shifting index
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Base Case fill index by 0
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n2; j++)
    {
        dp[0][j] = 0;
    }

    // logic
    for (int index1 = 1; index1 <= n1; index1++)
    {
        for (int index2 = 1; index2 <= n2; index2++)
        {
            // string ko access krte time index ko shift krna hoga
            if (str1[index1 - 1] == str2[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];

                if (ans < dp[index1][index2])
                {
                    ans = dp[index1][index2];
                    // assing point for maximum substring last character
                    point = index1 - 1;
                }
            }

            else
            {
                dp[index1][index2] = 0;
            }
        }
    }

    string lcSubString = "";

    // update point
    point = point - ans + 1;
    for (int i = 0; i < ans; i++)
    {
        lcSubString.push_back(str1[point]);
        point++;
    }

    return lcSubString;
}

int main()
{
    string s1 = "abcjklp";
    string s2 = "acjkp";
    string lcSubString = lcsubstring2(s1, s2);

    cout << "lcsubstring : " << lcSubString << endl;
}