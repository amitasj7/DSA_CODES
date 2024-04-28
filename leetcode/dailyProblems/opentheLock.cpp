#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        int ans = -1;
        // check for deadends
        set<string> st;

        // Insert elements from the vector into the set
        st.insert(deadends.begin(), deadends.end());

        // take a visited vector

        vector<int> visited(10000, 0);

        // take a queue
        queue<pair<string, int>> q;

        q.push({"0000", 0});
        visited[0] = 1;

        while (!q.empty())
        {

            string str = q.front().first;
            ans = q.front().second;

            q.pop(); 

            if (str == target)
                return ans;

            if (st.find(str) != st.end())
                continue;

            // positive direction
            for (int i = 0; i < 4; i++)
            {
                string temp = str;
                char ch = temp[i];

                if (ch == '9')
                {
                    ch = '0';
                }
                else
                {
                    ch += 1;
                }

                temp[i] = ch;

                int val = stoi(temp);

                if (!visited[val])
                {
                    visited[val] = 1;
                    q.push({temp, ans + 1});
                }
            }
            // negative direction
            for (int i = 0; i < 4; i++)
            {
                string temp = str;
                char ch = temp[i];

                if (ch == '0')
                {
                    ch = '9';
                }
                else
                {
                    ch -= 1;
                }

                temp[i] = ch;

                int val = stoi(temp);

                if (!visited[val])
                {
                    visited[val] = 1;
                    q.push({temp, ans + 1});
                }
            }
        }

        return -1;
    }
};