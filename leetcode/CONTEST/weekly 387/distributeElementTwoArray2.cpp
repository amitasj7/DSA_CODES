#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size(), ub1, ub2, n1, n2;
        vector<int> nums1, nums2, v1, v2;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for (int i = 2; i < n; i++)
        {
            ub1 = upper_bound(v1.begin(), v1.end(), nums[i]) - v1.begin();
            ub2 = upper_bound(v2.begin(), v2.end(), nums[i]) - v2.begin();
            n1 = nums1.size(), n2 = nums2.size();
            if (n1 - ub1 > n2 - ub2)
            {
                nums1.push_back(nums[i]);
                v1.insert(v1.begin() + ub1, nums[i]);
            }
            if (n1 - ub1 < n2 - ub2)
            {
                nums2.push_back(nums[i]);
                v2.insert(v2.begin() + ub2, nums[i]);
            }
            if (n1 - ub1 == n2 - ub2)
            {
                if (n2 < n1)
                {
                    nums2.push_back(nums[i]);
                    v2.insert(v2.begin() + ub2, nums[i]);
                }
                else
                {
                    nums1.push_back(nums[i]);
                    v1.insert(v1.begin() + ub1, nums[i]);
                }
            }
        }
        for (int i = 0; i < nums2.size(); i++)
            nums1.push_back(nums2[i]);
        return nums1;
    }
};
class Solution
{
public:
    vector<int> resultArray(vector<int> nums)
    {
        vector<int> list, list1;

        list.push_back(nums[0]);
        list1.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            int a = count(list, nums[i]);
            int b = count(list1, nums[i]);

            if (a > b)
            {
                list.push_back(nums[i]);
            }
            else if (a < b)
            {
                list1.push_back(nums[i]);
            }
            else if (a == b)
            {
                int s1 = list.size();
                int s2 = list1.size();
                if (s1 <= s2)
                {
                    list.push_back(nums[i]);
                }
                else
                {
                    list1.push_back(nums[i]);
                }
            }
        }

        int i = 0;
        for (int ele : list)
        {
            nums[i] = ele;
            i++;
        }
        for (int ele : list1)
        {
            nums[i] = ele;
            i++;
        }

        return nums;
    }

    int count(vector<int> list, int ele)
    {
        int cnt = 0;
        for (int a : list)
        {
            if (a > ele)
                cnt++;
        }
        return cnt;
    }
};

class Solution
{
public:
    int greaterCount(vector<int> &vec, int value)
    {

        int count = 0;
        for (int i = 0; i < vec.size(); i++)
        {

            if (vec[i] > value)
            {
                count++;
            }
        }
        return count;
    }

    vector<int> resultArray(vector<int> &nums)
    {

        vector<int> v1, v2;

        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        int i = 2;

        while (i < nums.size())
        {
            int value = nums[i];

            int greaterValue1 = greaterCount(v1, value);
            int greaterValue2 = greaterCount(v2, value);

            if (greaterValue1 > greaterValue2)
            {
                v1.push_back(value);
            }
            else if (greaterValue1 < greaterValue2)
            {
                v2.push_back(value);
            }
            else
            {
                if (v1.size() > v2.size())
                {
                    v2.push_back(value);
                }
                else
                {
                    v1.push_back(value);
                }
            }

            i++;
        }

        v1.insert(v1.end(), v2.begin(), v2.end());

        return v1;
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> result = sol.resultArray(nums);

    cout << "Result: [";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
