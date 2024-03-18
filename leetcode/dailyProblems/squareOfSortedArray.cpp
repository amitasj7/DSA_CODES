#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {

        // take a priority queue -- min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            int square = nums[i] * nums[i];
            pq.push(square);
        }

        // now replace value in nums vector

        nums.clear();
        while (!pq.empty())
        {

            int value = pq.top();
            pq.pop();
            nums.push_back(value);
        }
        return nums;
    }
};