#include <bits/stdc++.h>
using namespace std;

// using BFS
class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        int ans = 0;

        // take a set data structure
        set<int> st;
        st.insert(restricted.begin(), restricted.end());

        vector<vector<int>> adj(n);

        // create adjecency list
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // take a visited vector
        vector<int> visited(n, 0);

        // take a queue
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        ans++;

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            // visit all neighbour

            for (auto &it : adj[node])
            {

                if (st.find(it) == st.end() && !visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                    ans++;
                }
            }
        }

        return ans;
    }
};