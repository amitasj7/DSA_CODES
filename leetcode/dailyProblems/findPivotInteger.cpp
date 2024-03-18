#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int totalSum = ((n * n) + n) / 2;

        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;

            // totalSum -(sum-i) = sum
            if (totalSum + i == 2 * sum)
            {
                return i;
            }
        }

        return -1;
    }
};