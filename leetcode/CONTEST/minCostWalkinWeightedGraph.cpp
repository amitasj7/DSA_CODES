#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int comp, vector<int> &visited, vector<int> &component, int &andval, vector<vector<vector<int>>> &adj)
    {
        // mark visited
        visited[node] = 1;

        // fill component
        component[node] = comp;

        // traverse all neighbours node
        for (auto &it : adj[node])
        {
            int newNode = it[0];
            int cost = it[1];

            if (!visited[newNode])
            {
                // perform  and operation
                andval = andval & cost;

                dfs(newNode, comp, visited, component, andval, adj);
            }
        }
    }

    vector<int> &findPair(vector<vector<int>> &vec, int key)
    {
        for (auto &pair : vec)
        {

            if (pair[0] == key)
            {
                return pair;
            }
        }

        static vector<int> empty;
        return empty;
    }
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        int m1 = query.size();

        vector<int> ans(m1, -1);

        vector<int> component(n, 1);

        unordered_map<int, int> mp;
        // <component, minANDvalue>

        // create Adjecency graph
        vector<vector<vector<int>>> adj(n);

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            // find key
            auto &result = findPair(adj[u], v);

            if (!result.empty() && result[1] > v)
            {
                result[1] = v;
            }
            else
            {
                adj[u].push_back({v, cost});
            }
            // find key
            result = findPair(adj[v], u);

            if (!result.empty() && result[1] > u)
            {
                result[1] = u;
            }
            else
            {
                adj[v].push_back({u, cost});
            }
        }

        vector<int> visited(n, 0);
        int comp = 1;

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                int andval = (2 << 30 << 1) - 1;

                // dfs ki help se component and mp ko fill kare
                dfs(i, comp, visited, component, andval, adj);
                mp[comp] = andval;
                comp += 1;
            }
        }

        // traverse query vector
        for (int i = 0; i < m1; i++)
        {
            int u = query[i][0];
            int v = query[i][1];

            if (component[u] != component[v])
            {
                ans[i] = -1;
            }
            else
            {
                int compVal = component[u];
                ans[i] = mp[compVal];
            }
        }

        return ans;
    }
};