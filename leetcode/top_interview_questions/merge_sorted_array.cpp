#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{


    // first m element ka vector le liye ->
    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }

    sort(nums1.begin(), nums1.end());
}
int main()
{

    vector<int> nums1, nums2;
    int m, n;

    InputVec(nums1);
    cin >> m;
    InputVec(nums2);
    cin >> n;

    merge(nums1, m, nums2, n);
    PrintVec(nums1);

    return 0;
}