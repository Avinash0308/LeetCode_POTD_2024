#include <bits/stdc++.h>
using namespace std;

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
    int solve(TreeNode *root, int val)
    {
        if (!root)
            return 0;
        int l = solve(root->right, val);
        int og = root->val;
        root->val = og + l + val;
        int r = solve(root->left, root->val);
        return og + l + r;
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        solve(root, 0);
        return root;
    }
};

int main()
{
    return 0;
}