#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

bool isLeafNode(TreeNode *root)
{
    return root->left == NULL && root->right == NULL;
}

void rootToLeafHelper(TreeNode *root, vector<string> &ans, string &str)
{

    str += to_string(root->val);

    if (isLeafNode(root))
    {

        ans.push_back(str);
        return;
    }
    rootToLeafHelper(root->left, ans, str);
    str.pop_back();

    rootToLeafHelper(root->right, ans, str);
    str.pop_back();
}
vector<string> allRootToLeaf(TreeNode *root)
{
    // Write your code here.
    vector<string> ans;
    string str = "";
    rootToLeafHelper(root, ans, str);

    return ans;
}

int main()
{
    TreeNode *root = makeTree();

   vector<int> ans =  allRootToLeaf(root);

   for(auto i : ans){
    cout<<i<<endl; 
   }
}