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

vector<int> IntersectionVec(vector<int> v1, vector<int> v2)
{

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> intersection;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersection));

    return intersection;
}
