#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isLeaf(TreeNode *root)
    {
        return root->left == NULL && root->right == NULL;
    }

    int helper(TreeNode *root, bool val)
    {

        // BASE CASE
        if (isLeaf(root))
        {
            if (val)
                return root->val;
            else
                return 0;
        }

        // LOGIC
        int sum = 0;
        if (root->left != NULL)
            sum += helper(root->left, true);

        if (root->right != NULL)
        {
            sum += helper(root->right, false);
        }

        return sum;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {

        // if left node then val == true

        int sum = helper(root, false);

        return sum;
    }
};