
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int sizeNums = nums.size();
        vector<int> accessNumsList[sizeNums];
        for (int i = 0; i < sizeNums - 1; i++)
        {
            accessNumsList[edges[i][0]].push_back(edges[i][1]);
            accessNumsList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> incrementVec;
        for (int i = 0; i < sizeNums; i++)
        {
            long long value = (long long)nums[i] ^ k;
            if (value > nums[i])
            {
                incrementVec.push_back(i);
            }
        }
        // cout<<incrementVec.size()<<endl;
        int sizeIncVec = incrementVec.size();
        if (sizeIncVec % 2 == 0)
        {
            long long ans = 0;
            for (int i = 0; i < sizeNums; i++)
            {
                ans += nums[i];
            }
            for (int i = 0; i < incrementVec.size(); i++)
            {
                ans = ans - nums[incrementVec[i]];
                long long add = (long long)nums[incrementVec[i]] ^ k;
                ans = ans + add;
            }
            return ans;
        }
        else
        {
            long long ans = 0;
            for (int i = 0; i < sizeNums; i++)
            {
                ans += (long long)nums[i];
            }
            long long finalAns = ans;

            for (int i = 0; i < incrementVec.size(); i++)
            {
                ans = ans - nums[incrementVec[i]];
                long long add = (long long)nums[incrementVec[i]] ^ k;
                ans = ans + add;
            }
            for (int i = 0; i < sizeIncVec; i++)
            {
                long long add = (long long)nums[incrementVec[i]] ^ k;
                long long currentValueAns = ans - add + nums[incrementVec[i]];
                finalAns = max(finalAns, currentValueAns);
            }

            vector<int> visitedVec(sizeNums, 0);
            long long sum = 0;
            for (int i = 0; i < sizeIncVec; i++)
            {
                visitedVec[incrementVec[i]] = 1;
            }
            for (int i = 0; i < sizeNums; i++)
            {
                if (visitedVec[i] == 0)
                {
                    long long add = (long long)nums[i] ^ k;
                    long long currentValueAns = ans - nums[i] + add;
                    finalAns = max(finalAns, currentValueAns);
                }
            }

            return finalAns;
        }
    }
};