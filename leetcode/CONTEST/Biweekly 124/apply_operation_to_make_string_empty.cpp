#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lastNonEmptyString(string s)
    {
        string ans = "";

        vector<int> occ(27, 0);

        for (int i = 0; i < s.size(); i++)
        {

            int index = s[i] - 'a' + 1;

            occ[index]++;
        }

        int maxFre = 0;

        vector<int> letter;
        // traverse occ
        for (int i = 1; i <= 26; i++)
        {

            if (maxFre < occ[i])
            {

                letter.clear();
                letter.push_back(i);
                maxFre = occ[i];
            }
            else if (maxFre == occ[i])
            {
                letter.push_back(i);
            }
        }

        for (int i = s.size() - 1; i >= 0 && !letter.empty(); i--)
        {
            int index = s[i] - 'a' + 1;

            auto it = find(letter.begin(), letter.end(), index);

            if (it != letter.end())
            {
                ans += char('a' + index - 1);
                letter.erase(it);
                continue;
            }

            // s.erase(i, 1);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};