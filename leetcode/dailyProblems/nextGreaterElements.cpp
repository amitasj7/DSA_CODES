#include <bits/stdc++.h>
using namespace std;

// index: 012345
// given: 124651
// ans : 125146
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int len = s.length();

        // find consecutive left smaller index
        int index = -1;
        int nextindex = -1;
        for (int i = len - 2; i >= 0; i--)
        {
            int val = s[i] - '0';
            int nextval = s[i + 1] - '0';

            if (val < nextval)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            return -1;
        }

        for (int i = len - 1; i > index; i--)
        {
            int val = s[i] - '0';
            if (val > s[index] - '0')
            {
                nextindex = i;
            }
        }

        if(nextindex == -1){  
            return -1; 
        }

        swap(s[index], s[nextindex]);

        reverse(s.begin() + index + 1, s.end());

        int ans = stoi(s);

        return ans;
    }
};

// circular array
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> stk;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int current = nums[i % n];

            while (!stk.empty() && stk.top() <= current)
            {
                stk.pop();
            }

            // phle 2n-1 se n-1 tak only stack me element order sahi krege n-1 se ans me store krna start krege
            if (i < n && !stk.empty())
            {
                ans[i] = stk.top();
            }

            stk.push(current);
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans(n1, -1);

        // store nums1 into hashmap
        // <element ,index>
        unordered_map<int, int> mp;

        for (int i = 0; i < n1; i++)
        {
            mp[nums1[i]] = i;
        }

        // take stack
        // <elements of nums2>
        stack<int> stk;

        // traverse nums2 complete

        for (int i = n2 - 1; i >= 0; i--)
        {

            int current = nums2[i];

            // pop all smaller and equal element
            while (!stk.empty() && current >= stk.top())
            {
                stk.pop();
            }
            auto it = mp.find(current);
            // element find
            if (it != mp.end() && !stk.empty())
            {

                ans[it->second] = stk.top();
            }

            stk.push(current);

            // mp.erase(it);
        }

        return ans;
    }
};