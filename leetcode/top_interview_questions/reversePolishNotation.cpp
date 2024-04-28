#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {

        int ans = 0;

        // take a stack data structure
        stack<int> st;

        int n = tokens.size();
        // traverse tokens vec

        for (auto &it : tokens)
        {

            if (it == "+")
            {
                // pop two value and calculate them

                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                ans = val1 + val2;
            }
            else if (it == "-")
            {
                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                ans = val1 - val2;
            }
            else if (it == "*")
            {
                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                ans = val1 * val2;
            }
            else if (it == "/")
            {
                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                ans = val1 / val2;
            }
            else
            {
                ans = stoi(it);
            }
            st.push(ans);
        }

        return ans;
    }
};