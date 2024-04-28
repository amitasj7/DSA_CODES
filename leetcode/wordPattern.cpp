#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        int p1 = pattern.size();
        int s1 = s.size();

        // take a vector of string

        vector<string> vec;
        string str = "";

        // vec me string ko fill kare
        for (int i = 0; i < s1; i++)
        {

            char ch = s[i];

            if (ch == ' ')
            {
                vec.push_back(str);
                str = "";
            }
            else
                str += ch;
        }
        vec.push_back(str);

        int n = vec.size();
        if (n != p1)
            return false;

        map<char, string> mp;
        set<string> st;

        // map pattern character to word
        for (int i = 0; i < p1; i++)
        {

            char ch = pattern[i];

            // if key doesn't exist then map it

            if (mp.find(ch) == mp.end())
            {
                mp[ch] = vec[i];
                st.insert(vec[i]);
            }
            else
            {
                if (mp[ch] != vec[i])
                {
                    return false;
                }
            }
        }

        // put into set check for abba  and dog dog dog dog

        if (st.size() != mp.size())
            return false;

        return true;
    }
};
