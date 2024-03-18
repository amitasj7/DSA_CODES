#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrefix(int value1, int value2)
    {
        string str1 = to_string(value1);
        string str2 = to_string(value2);

        int i = 0;

        int size = min(str1.size(), str2.size());

        while (i < size)
        {

            if (str1[i] != str2[i])
            {
                break;
            }

            i++;
        }
        return i;
    }
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {

        int lengthLCP = 0;

        int s1 = arr1.size();
        int s2 = arr2.size();

            for (int i = 0; i < s1; i++)
        {
            for (int j = 0; j < s2; j++)
            {

                lengthLCP = max(lengthLCP, isPrefix(arr1[i], arr2[j]));
            }
        }

        return lengthLCP;
    }
};