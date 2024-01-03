#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using two stack approach
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;

    // take two stack
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    // push root in stack1
    st1.push(root);

    while (!st1.empty())
    {

        // st1.pop kuch bhi return nahi krta hai
        root = st1.top();
        st1.pop();

        // push in stack2
        st2.push(root);

        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}
// using single stack method
vector<int> postorderTraversal2(TreeNode *root)
{
    TreeNode *current = root;
    vector<int> ans;
    if (current == NULL)
        return ans;

    stack<TreeNode *> st;

      while (current != NULL || !st.empty())
    {
        // current null nahi hai to 1. stack ke andar push karege 2. current ko left child se connect krege
        if (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else
            {
                current = temp;
            }
        }
    }
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    vector<int> ans = postorderTraversal2(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}