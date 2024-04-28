#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    bool same(vector<vector<int>> &grid, int x, int y, int size)
    {

        int val = grid[x][y];
        for (int i = x; i < x + size; i++)
        {
            for (int j = y; j < y + size; j++)
            {

                if (val != grid[i][j])
                    return false;
            }
        }
        return true;
    }
    Node *helper(vector<vector<int>> &grid, int x, int y, int size)
    {
        // BASE CASEE
        if (same(grid, x, y, size))
        {
            Node *node = new Node(grid[x][y], true);
            return node;
        }

        // LOGIC
        Node *root = new Node(1, false);
        int newSize = size / 2; // update this value according to its parent
        root->topLeft = helper(grid, x, y, newSize);
        root->topRight = helper(grid, x, y + newSize, newSize);

        root->bottomLeft = helper(grid, x + newSize, y, newSize);
        root->bottomRight = helper(grid, x + newSize, y + newSize, newSize);

        /// RETURN
        return root;
    }
    Node *construct(vector<vector<int>> &grid)
    {

        int n = grid.size();

        return helper(grid, 0, 0, n);
    }
};