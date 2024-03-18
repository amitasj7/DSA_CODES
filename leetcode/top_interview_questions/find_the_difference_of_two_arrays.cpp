#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"
vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{

    vector<vector<int>> finalans;

    vector<int> intersec = IntersectionVec(nums1, nums2);

    set<int> ans1, ans2;
    for (int i = 0; i < nums1.size(); i++)
    {
        auto it = find(intersec.begin(), intersec.end(), nums1[i]);
        if (it != intersec.end())
        {
            continue;
        }
        else
        {
            ans1.insert(nums1[i]);
        }
    }
    vector<int> finalans1(ans1.begin(), ans1.end());
    finalans.push_back(finalans1);

    for (int i = 0; i < nums2.size(); i++)
    {
        auto it = find(intersec.begin(), intersec.end(), nums2[i]);
        if (it != intersec.end())
        {
            continue;
        }
        else
        {
            ans2.insert(nums2[i]);
        }
    }
    vector<int> finalans2(ans2.begin(), ans2.end());
    finalans.push_back(finalans2);

    return finalans;
}
int main()
{
    vector<int> nums1;
    vector<int> nums2;

    InputVec(nums1);
    InputVec(nums2);

    vector<vector<int>> ans = findDifference(nums1, nums2);

    for (auto it : ans)
    {
        PrintVec(it);
    }

    return 0;
}