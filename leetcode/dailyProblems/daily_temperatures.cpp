#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        // store index value in stack
        stack<int> st;

        int n = temperatures.size();
        vector<int> ans(n, 0);

        // push last element in stack
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {

            int currentTemp = temperatures[i];


            while (!st.empty() && temperatures[st.top()] <= currentTemp)
            {
                st.pop();
            }
            // if not find any greater value and stack empty to 0 otherwise count ans;
            if (!st.empty())
            {
                ans[i] = st.top() - i;
            }

            // now push into stack
            st.push(i);
        }

        return ans;
    }
};