#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {

        int i = 0;
        int j = 0;

        while (j < s.size())
        {

            if (s[j] == '1')
            {
                s[j] = '0';
                s[i] = '1';

                i++;
            }

            j++;
        }

        s[i - 1] = '0';
        s[s.size() - 1] = '1';

        return s;
    }
    string maximumOddBinaryNumber(string s)
    {

        int i = 0;
        int j = 0;

        while (i < s.size())
        {

            if (j < s.size() && s[j] == '1')
            {
                s[i] = '1';
                i++;
            }

            if (j >= s.size())
            {

                s[i - 1] = '0';
                i++;
            }
            j++;
        }

        s[i - 1] = '1';

        return s;
    }
    string maximumOddBinaryNumber(string s)
    {

        string ans;

        int one = 0;

        // traverse whole string and find 1
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '1')
            {

                one++;
            }
        }
        int zeros = s.size() - one;

        while (one != 1)
        {
            ans = ans + '1';
            one--;
        }

        while (zeros--)
        {
            ans = ans + '0';
        }

        ans = ans + '1';

        return ans;
    }
};