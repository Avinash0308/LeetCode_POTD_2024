#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.*/
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
        if (!root)
            return false;
        if (!(root->left) && !(root->right))
            return true;
        return false;
    }
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        return solve(root->left) + solve(root->right) + (isLeaf(root->left) ? root->left->val : 0);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        return solve(root);
    }
};

int main()
{
    return 0;
}