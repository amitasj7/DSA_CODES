#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int visited[], int size, vector<vector<int>> &isConnected)
    {

        visited[node] = 1;

        for (int i = 0; i < size; i++)
        {
            if (i == node)
                continue;

            if (isConnected[node][i] == 1 && visited[i] == 0)
            {
                dfs(i, visited, size, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int size = isConnected.size();

        int visited[size] = {0};
        int provinces = 0;

        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                provinces++;

                dfs(i, visited, size, isConnected);
            }
        }

        return provinces;
    }
};