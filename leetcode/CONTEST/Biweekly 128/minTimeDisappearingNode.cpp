#include <bits/stdc++.h>
using namespace std;

// using vector
class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {

        // create adjaceny list
        vector<vector<vector<int>>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];

            // don't take self loop
            if (u == v)
                continue;

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<int> dist(n, INT_MAX); // Initialize all distances as infinity

        // take min heap = <distance,node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        dist[0] = 0;
        minHeap.push({0, 0});

        while (!minHeap.empty())
        {

            int node = minHeap.top().second;
            int distance = minHeap.top().first;

            minHeap.pop();

            if (distance > dist[node] || distance >= disappear[node])
                continue;

            dist[node] = distance;

            for (auto it : adj[node])
            {
                int newNode = it[0];
                int edgeWt = it[1];

                int totaldistance = distance + edgeWt;

                if (totaldistance < dist[newNode])
                {

                    // update distance

                    minHeap.push({totaldistance, newNode});
                }
            }
        }

        // traverse distance
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] >= INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

// using map
class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {

        // create adjaceny list
        vector<map<int, int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];

            // don't take self loop
            if (u == v)
                continue;

            auto it = adj[u];

            // find minimum edges
            if (it.find(v) != it.end())
            {
                if (time < it[v])
                {

                    it[v] = time;
                    auto it2 = adj[v];
                    it[u] = time;
                }
            }
            else
            {

                adj[u][v] = time;
                adj[v][u] = time;
            }
        }

        vector<int> dist(n, INT_MAX); // Initialize all distances as infinity

        // take min heap = <distance,node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        dist[0] = 0;
        minHeap.push({0, 0});

        while (!minHeap.empty())
        {

            int node = minHeap.top().second;
            int distance = minHeap.top().first;

            minHeap.pop();

            for (auto it : adj[node])
            {

                int newNode = it.first;
                int edgeWt = it.second;

                int totaldistance = distance + edgeWt;

                if (totaldistance < disappear[newNode] && totaldistance < dist[newNode])
                {

                    // update distance
                    dist[newNode] = totaldistance;
                    minHeap.push({totaldistance, newNode});
                }
            }
        }

        // traverse distance
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] >= INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

// using dfs
class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<int> &ans, vector<map<int, int>> &edgeslist, vector<int> &disapper, int parentTime)
    {
        // mark visited
        visited[node] = 1;

        for (auto it : edgeslist[node])
        {
            int cnode = it.first;
            int time2 = it.second;
            int totalTime = parentTime + time2;

            if (!visited[cnode])
            {
                if (disapper[cnode] > totalTime)
                {
                    ans[cnode] = totalTime;

                    dfs(cnode, visited, ans, edgeslist, disapper, totalTime);
                }
            }
            else
            {
                if (ans[cnode] > totalTime)
                    ans[cnode] = totalTime;
            }
        }
    }

    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<int> ans(n, -1);
        ans[0] = 0;

        // create adjaceny list
        vector<map<int, int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];

            // don't take self loop
            if (u == v)
                continue;

            auto it = adj[u];

            // find minimum edges
            if (it.find(v) != it.end())
            {
                if (time < it[v])
                {

                    it[v] = time;
                    auto it2 = adj[v];
                    it[u] = time;
                }
            }
            else
            {

                adj[u][v] = time;
                adj[v][u] = time;
            }
        }
        vector<int> visited(n, 0);

        dfs(0, visited, ans, adj, disappear, 0);

        return ans;
    }
};
