#include <bits/stdc++.h>
using namespace std;

void InputVec(vector<int> &nums)
{
    cout << "Enter Vector input (terminate -1)" << endl;
    int x;
    cin >> x;
    while (x != -1)
    {
        nums.push_back(x);
        cin >> x;
    }
}
void PrintVec(vector<int> &nums)
{
    // cout << "size : " << v.size() << endl;
    for (int i = 0; i < nums.size(); ++i)
    {
        // v.size() --> o(1)
        cout << nums[i] << " ";
    }
    cout << endl;
}
void InputVecPair(vector<pair<int, int>> &ans, vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> input;
        input.first = nums[i];
        input.second = i;
        ans.push_back(input);
    }
}
vector<int> twoSum(vector<int> &nums, int target)

{

    vector<pair<int, int>> ans;

    InputVecPair(ans, nums);
    sort(ans.begin(), ans.end());

    vector<int> final_ans;

    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        if ((ans[i].first + ans[j].first) == target)

        {
            final_ans.push_back(ans[i].second);
            final_ans.push_back(ans[j].second);

            break;
        }
        else
        {
            ((ans[i].first + ans[j].first) > target) ? (j--) : (i++);
        }
    }
    return final_ans;
}
int main()
{
    vector<int> nums;
    
    InputVec(nums);
    PrintVec(nums);
    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);
    PrintVec(ans);

    return 0;
}