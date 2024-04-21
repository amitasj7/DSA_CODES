#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {

        long long ans = 0;

        // sort nums

        sort(nums.begin(), nums.end());

        // find median Even and Odd case Both

        int n = nums.size();
        int median = -1;

        // odd case
        if (n % 2 == 1)
        {
            median = n / 2;
        }
        // Even case
        else
        {
            median = (nums[n / 2] >= nums[(n / 2) - 1]) ? n / 2 : (n / 2) - 1;
        }

        // check previous value  is less than equal

        ans += abs(k - nums[median]);
        int pre = median - 1;
        while (pre >= 0 && nums[pre] > k)
        {

            int diff = nums[pre] - k;

            ans += (long long)diff;
            pre--;
        }

        // check next value is greater than equal
        int next = median + 1;
        while (next < n && nums[next] < k)
        {
            int diff = k - nums[next];
            ans += (long long)diff;
            next++;
        }

        return ans;
    }
};

class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0;

        int n = nums.size();
        // odd cases
        if (n % 2 == 1)
        {

            // find n/2

            int median = n / 2;

            while (nums[median] != k)
            {

                int diff = k - nums[median];

                nums[median] += diff;

                ans += (long long)abs(diff);

                sort(nums.begin(), nums.end());
            }
        }

        // even cases
        else
        {

            // find n/2

            int median1 = n / 2;
            int median2 = median1 - 1;

            int median = (nums[median1] > nums[median2]) ? median1 : median2;

            while (nums[median] != k)
            {

                int diff = k - nums[median];

                nums[median] += diff;

                ans += (long long)abs(diff);

                sort(nums.begin(), nums.end());
                median = (nums[median1] > nums[median2]) ? median1 : median2;
            }
        }

        return ans;
    }
};