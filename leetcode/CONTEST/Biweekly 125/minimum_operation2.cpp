#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{

    int ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> minheap;

    int size = nums.size();
    // visite nums and create minheap
    for (int j = 0; j < size; j++)
    {
        minheap.push((long long)nums[j]);
    }

    // apply on minheap

    long topValue = minheap.top();
    while (topValue < k)
    {
        // take two elements

        ans++;
        long long small1 = minheap.top();
        minheap.pop();
        long long small2 = minheap.top();
        minheap.pop();

        long long newValue = (long long)(min(small1, small2) * 2) + max(small1, small2);

        minheap.push(newValue);

        topValue = minheap.top();
    }

    return ans;
}

int main()
{

    vector<int> nums = {
        2,
        11,
        10,
        1,
        3,
    };

    cout << minOperations(nums, 10) << endl;
}