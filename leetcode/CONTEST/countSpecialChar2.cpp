#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> cap(26, 0);

        map<char, bool> mp;
        int n = word.size();

        int ans = 0;

        // traverse word string
        for (int i = 0; i < n; i++)
        {

            char ch = word[i];

            if (ch >= 'A' && ch <= 'Z')
            {
                int index = ch - 'A';
                cap[index] = 1;
            }
            else
            {
                int lower = (ch - 32) - 'A';
                if (cap[lower] == 1)
                {
                    mp[ch] = false;
                }
                else
                {
                    mp[ch] = true;
                }
            }
        }

        // traverse cap
        for (int i = 0; i < 26; i++)
        {

            if (cap[i] == 1)
            {
                char small = i + 'a';

                if (mp.find(small) != mp.end() && mp[small])
                {
                    ans++;
                }
            }
        }

        // return

        return ans;
    }
};