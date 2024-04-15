#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];

            for (int j = 1; j <= k; j++)
            {
                pq.push(coin * j);
            }
        }

        while (k > 0)
        {
            pq.pop();
        }
        return pq.top();
    }
};
struct Pair
{
    long long value;
    int count;

    Pair(long long v, int c) : value(v), count(c) {}
};

struct Compare
{
    bool operator()(const Pair &p1, const Pair &p2)
    {
        return p1.value > p2.value;
    }
};

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        priority_queue<Pair, vector<Pair>, Compare> pq;

        for (int i = 0; i < coins.size(); i++)
        {
            pq.push(Pair(coins[i], 1));
        }

        while (true)
        {
            Pair current = pq.top();
            pq.pop();
            if (k == 1)
                return current.value;
            k--;

            pq.push(Pair(current.value + coins[current.count], current.count + 1));
        }
    }
};

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        sort(coins.begin(), coins.end());

        long long ans = coins[0] * k;

        int n = coins.size();

        for (int i = 1; i < n; i++)
        {
            // multiple then continue
            if (coins[i] % coins[0] == 0)
                continue;

            int newCoin = coins[i];
            int mul = 1;
            long long newval = newCoin * mul;
            while (newval < ans)
            {
                // coins 0th  multiple hai ki nahi
                if (newval % coins[0] != 0)
                {
                    ans -= coins[0];
                }

                mul++;

                newval = newCoin * mul;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        // sort(coins.begin(),coins.end());

        //  long long ans = coins[0]*k;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;

        pq.push(0);
        seen.insert(0);

        while (k > 0)
        {
            long long current = pq.top();
            pq.pop();

            for (int coin : coins)
            {
                long long next = current + coin;
                if (seen.find(next) == seen.end())
                {
                    pq.push(next);
                    seen.insert(next);
                }
            }

            k--;
        }

        return pq.top();
    }
};
class Solution
{
public:
    string findLatestTime(string s)
    {
        int n1 = s.size();

        for (int i = 0; i < n1; i++)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    if (s[1] == '?' || s[1] == '0' || s[1] == '1')
                    {
                        s[0] = '1';
                    }

                    else
                    {
                        s[0] = '0';
                    }
                }
                else if (i == 1)
                {

                    if (s[0] == '1')
                    {
                        s[1] = '1';
                    }
                    else
                    {
                        s[1] = '9';
                    }
                }
                else if (i == 3)
                {
                    s[i] = '5';
                }
                else if (i == 4)
                {
                    s[i] = '9';
                }
            }
        }

        return s;
    }
};

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int> &nums)
    {
        int ans = 0;
        int minPrime = -1, maxPrime = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (isPrime(nums[i]))
            {
                if (minPrime == -1)
                {
                    minPrime = i;
                }
                maxPrime = i;
            }
        }

        if (minPrime != -1 && maxPrime != -1)
        {
            ans = maxPrime - minPrime;
        }

        return ans;
    }
};

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
