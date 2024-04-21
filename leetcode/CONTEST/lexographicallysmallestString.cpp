#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(string s, int k)
    {

        string ans = "";
        // traverse string s

        for (int i = 0; i < s.size(); i++)
        {
            // find clockWise and anticlockWise cost
            int clock = 'z' - s[i] + 1;
            int antiClock = s[i] - 'a';

            int miniCost = min(antiClock, clock);

            if (k >= miniCost)
            {
                ans += 'a';

                k -= miniCost;
            }
            else
            {
                char ch = s[i] - k;
                ans += ch;

                k = 0;
            }
        }

        return ans;
    }
};