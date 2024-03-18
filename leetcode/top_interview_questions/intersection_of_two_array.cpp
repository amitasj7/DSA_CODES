#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)

    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        vector<int> ans;

        while (j != nums2.size() || i != nums1.size())
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back((nums1[i]));
                i++;
                j++;
            }
            else
            {

                (nums1[i] > nums2[j]) ? j++ : i++;
            }
        }

        return ans;
    }
};
void PrintVec(vector<int> &v)
{
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        // v.size() --> o(1)
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums1, nums2;

    int x;
    cin >> x;

    while (x >= 0 && x <= 1000)
    {
        nums1.push_back(x);
        cin >> x;
    }
    PrintVec(nums1);

    cin >> x;
    while (x >= 0 && x <= 1000)
    {
        nums2.push_back(x);
        cin >> x;
    }
    PrintVec(nums2);

    Solution ans;

    vector<int> v = ans.intersect(nums1, nums2);
    PrintVec(v);

    return 0;
}
