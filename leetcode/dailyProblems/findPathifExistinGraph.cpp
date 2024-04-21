#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int comp, vector<int> &visited, vector<int> &component, vector<vector<int>> &adj)
    {

        // mark visited
        visited[node] = 1;

        // fill component
        component[node] = comp;

        // traverse all neighbours node
        for (auto &it : adj[node])
        {
            int newNode = it;

            if (!visited[newNode])
            {

                dfs(newNode, comp, visited, component, adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        // create Adjecency graph
        vector<vector<int>> adj(n);

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int comp = 1;
        vector<int> component(n, 1);

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {

                // dfs ki help se component and mp ko fill kare
                dfs(i, comp, visited, component, adj);
                comp += 1;
            }
        }

        if (component[source] == component[destination])
            return true;

        return false;
    }
};