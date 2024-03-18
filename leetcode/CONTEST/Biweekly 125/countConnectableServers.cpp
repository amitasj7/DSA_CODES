#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsHelper(int node, int pairofValue, int value, int weight, int &ans, vector<vector<pair<int, int>>> &adjGraph)
    {
        if (weight % value == 0)
        {
            ans++;
        }
        for (pair<int, int> it : adjGraph[node])
        {
            if (it.first == pairofValue)
            {
                continue;
            }
            dfsHelper(it.first, node, value, it.second + weight, ans, adjGraph);
        }
    }
    int findHelper(int node, int s, vector<vector<pair<int, int>>> &adjGraph)
    {
        vector<int> vec;
        int totalSum = 0;
        for (pair<int, int> it : adjGraph[node])
        {
            int ans = 0;
            dfsHelper(it.first, node, s, it.second, ans, adjGraph);
            vec.push_back(ans);
            totalSum += ans;
        }
        int ans = 0;
        for (int it : vec)
        {
            totalSum -= it;
            ans += it * totalSum;
        }
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int s)
    {
        int size = edges.size() + 1;
        vector<vector<pair<int, int>>> adjGraph(size + 1);
        for (auto it : edges)
        {
            adjGraph[it[0]].push_back({it[1], it[2]});
            adjGraph[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ans(size, 0);
        for (int i = 0; i < size; i++)
        {
            ans[i] += findHelper(i, s, adjGraph);
            cout << ans[i] << endl;
        }
        return ans;
    }
};