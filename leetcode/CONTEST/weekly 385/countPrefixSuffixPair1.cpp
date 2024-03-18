#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        // for prefix
        int i = 0;

        int size = str1.size();

        while (i < size)
        {

            if (str1[i] != str2[i])
            {
                return false;
            }
            i++;
        }

        // for suffix
        i = size - 1;

        int j = str2.size()-1; 

        while (i >= 0)
        {

            if (str1[i] != str2[j])
            {
                return false;
            }

            i--;
            j--; 
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string> &words)
    {

        int count = 0;

        int size = words.size();
        int i = 0;

        while (i <= (size - 2))
        {
            int j = i + 1;

            while (j < size)
            {

                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    // cout << "true" << endl;
                    count++;
                }

                j++;
            }
            i++;
        }

        return count;
    }
};

int main()
{

    Solution s;
    vector<string> words = {"a", "abb"};

    cout<<s.countPrefixSuffixPairs(words)<<endl;
}