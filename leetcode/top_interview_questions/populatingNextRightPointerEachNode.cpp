#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return root;

        // take a Queue
        queue<pair<Node *, int>> q;

        q.push({root, 1});

        // travere whole tree

        while (!q.empty())
        {
            auto node = q.front().first;
            int level = q.front().second;

            q.pop();

            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});

            // if last node
            if (q.empty())
            {
                node->next = NULL;
            }

            else
            {
                auto nextNode = q.front().first;
                int nextLevel = q.front().second;

                if (level != nextLevel)
                    node->next = NULL;

                else
                {

                    node->next = nextNode;
                }
            }
        }

        return root;
    }
};