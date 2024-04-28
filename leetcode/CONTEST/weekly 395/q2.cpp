#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());



        unordered_map<int, int> mpX;


        int minX = INT_MAX;




        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int x = nums2[j] - nums1[i];
                mpX[x]++;
            }
        }



        for (auto &[ x, count] : mpX)
        {
            vector<int> match(nums1.size());


            for (int i = 0; i < nums1.size(); i++)
            {
                match[i] = nums1[i] + x;
            }


            sort(match.begin(), match.end());

            if (helper(match, nums2))
            {
                minX = min(minX, x);
            }
            
        }

        return minX;
    }

    bool helper(vector<int> &match, vector<int> &nums2)
    {
        int i = 0, j = 0, skip = 2;

        while (i < match.size() && j < nums2.size())
        {
            if (match[i] == nums2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
                skip--;
                if (skip < 0)
                {
                    return false;
                }
            }
        }

        return j == nums2.size() && (i - j) <= 2;
    }
};
