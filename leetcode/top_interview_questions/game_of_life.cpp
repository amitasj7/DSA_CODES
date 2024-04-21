#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalLive(vector<vector<int>> &board, int totalRow, int totalCol,
                  int row, int col)
    {

        int one = 0;

        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < 8; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // check valid or not
            if (newRow >= 0 && newRow < totalRow && newCol >= 0 &&
                newCol < totalCol && abs(board[newRow][newCol]) == 1)
            {
                one++;
            }
        }

        return one;
    }
    void gameOfLife(vector<vector<int>> &board)
    {

        int totalRow = board.size();
        int totalCol = board[0].size();

        // traverse whole board
        for (int i = 0; i < totalRow; i++)
        {

            for (int j = 0; j < totalCol; j++)
            {
                int one = totalLive(board, totalRow, totalCol, i, j);
                if (board[i][j] == 1)
                {
                    if (one < 2 || one > 3)
                    {
                        board[i][j] = -1;
                    }
                }
                else
                {

                    if (one == 3)
                    {
                        board[i][j] = 2;
                    }
                }
            }
        }

        // modify the board in term of 0 and 1
        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                if (board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};