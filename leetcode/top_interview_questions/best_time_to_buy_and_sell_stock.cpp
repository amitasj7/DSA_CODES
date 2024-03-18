#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"
/*
// ye kuch cases ke liye sahi nahi hai [2,4,1]
int maxProfit(vector<int> &prices)

{

    pair<int, int> min; // INT16_MAX mean = 32767
    min.first = INT16_MAX;
    min.second = -1;
    int max = INT16_MIN;

    int ans;

    for (int i = 0; i < prices.size(); i++)
    {
        if (min.first > prices[i])
        {
            // update min for store minimum value
            min.first = prices[i];
            min.second = i;
        }
    }
    int count = 0;

    for (int i = min.second + 1; i < prices.size(); i++)
    {
        if (prices[i] > min.first && prices[i] > max)
        {
            max = prices[i];
            count = 1;
        }
    }
    if (count == 0)
    {
        max = min.first;
    }

    ans = max - min.first;

    return ans;
}
 */
/*
int maxProfit(vector<int> &prices)

{
    vector<pair<int, int>> helper;

    for (int i = 0; i < prices.size(); i++)
    {
        pair<int, int> p;
        p.first = prices[i];
        p.second = i;

        helper.push_back(p);
    }
    sort(helper.begin(), helper.end());

    for (int i = 0; i < prices.size(); i++)
    {
        if (helper.back().second > helper[i].second)
        {
            return (helper.back().first - helper[i].first);
        }
    }
    return 0;
 }
 */
int maxProfit1(vector<int> &prices)

{
    vector<pair<int, int>> helper;

    for (int i = 0; i < prices.size(); i++)
    {
        pair<int, int> p;
        p.first = prices[i];
        p.second = i;

        helper.push_back(p);
    }
    sort(helper.begin(), helper.end());

    int i = 0, j = prices.size() - 1;
    vector<int> ans;

    for (i = 0; i < j; i++)
    {
        while (i < j)
        {
            if (helper[i].second < helper[j].second)
            {
                int push = helper[j].first - helper[i].first;
                ans.push_back(push);
                break;
            }
            else
            {
                j--;
            }
        }
        j = prices.size() - 1;
    }
    ans.push_back(0);

    sort(ans.begin(), ans.end());
    return ans.back();
}

int maxProfit(vector<int> &prices)
{

    int profit = 0, mini = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - min;

        if (cost > profit)
            profit = cost;

        mini = min(min, prices[i]);
    }

    return profit;
}

int main()
{

    vector<int> prices;

    InputVec(prices);
    cout << maxProfit(prices) << endl;

    return 0;
}