#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int row, int col, int current, vector<vector<int>> &visited, vector<vector<char>> &board, int totalRow, int totalCol, string &word, int n)
    {
        if (current == n)
            return true;

        // mark visited
        visited[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {

            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol && board[newRow][newCol] == word[current + 1] && dfs(newRow, newCol, current + 1, visited, board, totalRow, totalCol, word, n))
            {
                return true;
            }
            visited[newRow][newCol] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        int totalRow = board.size();
        int totalCol = board[0].size();

        // find first char
        vector<vector<int>> visited(totalRow, vector<int>(totalCol, 0));
        int n = word.size();

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {

                if (word[0] == board[i][j] && dfs(i, j, 0, visited, board, totalRow, totalCol, word, n))
                {
                    return true;
                }
            }
        }

        return false;
    }
};