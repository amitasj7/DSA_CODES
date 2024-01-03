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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;

        while (true)
        {
            if (root == NULL)
            {
                // stack top value print
                // update root
                if (st.empty())
                    break;

                root = st.top();
                st.pop();

                ans.push_back(root->val);
                root = root->right;

                // update root
            }
            else
            {
                // push into stack that node
                st.push(root);

                // update root
                root = root->left;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> st;
    st.push_back(3);

    cout << st[0] << endl;
}