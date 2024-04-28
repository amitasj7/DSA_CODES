#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    auto helper(int n, int x)
    {
        if ((x & (x - 1)) == 0)
            return x + n - 1;

        int p2 = 1;
        while (p2 < x)
            p2 <<= 1;

        if (p2 - 1 == x)
        {
            while (--n)
            {
                x = ((x + 1) * 2) - 1;
            }
            return x;
        }

        for (int i = x; i < p2; i++)
        {
            if ((i & x) == x)
                n--;
            if (n == 0)
                return i;
        }

        return p2;
    }
    long long minEnd(int n, int x)
    {
        return helper(n, x);
    }
};

class Solution
{
public:
    auto helper(int count, int val)
    {
        long long ans = val, mask = 1;

        vector<int> ansHelper;
        for (int i = 0; i < 63; i++)
        {
            if (ans >> i & mask ^ mask)
            {
                ansHelper.push_back(i);
            }
        }


        int ansHelperSize = ansHelper.size();
        for (long long i = 0; i < (mask << ansHelperSize); i++)
        {
            if (--count == 0)
            {
                for (int j = 0; j < 63; j++)
                {
                    if (i >> j & mask)
                    {
                        ans |= mask << ansHelper[j];
                    }
                }
                return ans;
            }
        }
        return ans;
    }
    long long minEnd(int n, int x)
    {

        return helper(n, x);
    }
};

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        if (n == 1)
            return x;

        vector<long long> nums(n);
        nums[0] = x;
        long long current = x;
        for (int i = 1; i < n; i++)
        {
            current += 1;
            long long mask = 1;
            while ((current & mask) != x)
            {
                current |= mask;
                mask <<= 1;
            }
            nums[i] = current;
        }

        return nums[n - 1];
    }
};
class Solution
{
public:
    auto helper(int n, int x)
    {

        vector<long long> ans(n);

        ans[0] = x;

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + 1;
            while ((ans[i] & x) != x)
            {
                ans[i]++;
            }
        }

        int ansHelper = ans[n - 1];

        return ansHelper;
    }

    long long minEnd(int n, int x)
    {
        if (n == 1)
            return x;

        return helper(n, x);
    }
};