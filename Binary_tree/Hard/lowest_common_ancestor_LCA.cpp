#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    // base condition
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, TreeNode * p, TreeNode * q);

    TreeNode *right = lowestCommonAncestor(root->right, TreeNode * p, TreeNode * q);

    // total 4 condition = 1. dono null 2. left null, right not null 3. right null, left not null 4. dono not null
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    // condition 1. 2. 3. handle ho chuki hai

    else
    {
        return root;
    }
    // condition 4. handle
}