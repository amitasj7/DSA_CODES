#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string customSortString(string order, string s)
    {

        string ans = "";

        map<char, int> mp;

        for (int i = 0; i < order.length(); i++)
        {
            char ch = order[i];

            // find ch frequency in s
            for (int j = 0; j < s.length(); j++)
            {

                if (ch == s[j])
                {
                    mp[ch]++;
                }
            }
        }

        // create ans
        for (int i = 0; i < order.length(); i++)
        {
            char ch = order[i];

            auto it = mp.find(ch);

            if (it != mp.end())
            {
                for (int j = 0; j < it->second; j++)
                {
                    ans += ch;
                }
            }
        }

        // traverse s
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // if not found then add
            auto it = mp.find(ch);

            if (it == mp.end())
            {
                ans += ch;
            }
        }

        return ans;
    }
};