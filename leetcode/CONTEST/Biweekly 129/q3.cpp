#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    auto helper(int zero, int one, int limit)
    {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dpValue(one + 1, vector<vector<long long>>(zero + 1, vector<long long>(2, 0)));

        dpValue[0][0][0] = dpValue[0][0][1] = 1;

        for (int i = 0; i <= one; ++i)
        {
            for (int j = 0; j <= zero; ++j)
            {
                for (int k = 1; k <= limit; ++k)
                {
                    if (i - k >= 0)
                        dpValue[i][j][1] = (dpValue[i][j][1] + dpValue[i - k][j][0]) % MOD;
                    if (j - k >= 0)
                        dpValue[i][j][0] = (dpValue[i][j][0] + dpValue[i][j - k][1]) % MOD;
                }
            }
        }

        return static_cast<int>((dpValue[one][zero][0] + dpValue[one][zero][1]) % MOD);
    }
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int ans = helper(zero, one, limit);

        return ans;
    }
};
