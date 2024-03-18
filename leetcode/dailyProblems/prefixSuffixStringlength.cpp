#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s)
{

    int prefix = 0;
    int suffix = s.size() - 1;

    while (prefix < suffix)
    {
        if (s[prefix] == s[suffix])
        {

            // take proper prefix
            while ((prefix + 1) < s.size() && s[prefix] == s[prefix + 1])
            {
                prefix++;
            }
            // remove prefix

            s.erase(s.begin(), s.begin() + prefix + 1);
            // reset prefix
            prefix = 0;

            // take proper suffix
            suffix = s.size() - 1;
            while ((suffix - 1) >= 0 && s[suffix] == s[suffix - 1])
            {
                suffix--;
            }

            if (suffix >= 0)
                // remove suffix
                s.erase(s.begin() + suffix, s.end());
            // reset suffix
            suffix = s.size() - 1;
        }
        else
        {
            break;
        }
    }

    return s.size();
}

int main()
{
    // string str = "aabccabba";
    // string str = "ca";
    string str = "cabaabac";

    cout << minimumLength(str) << endl;
}