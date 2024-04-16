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
    void solve(TreeNode *root, int val, int cur, int depth)
    {
        if (!root)
            return;
        if (cur == depth - 1)
        {
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
            root->right->right = right;
            return;
        }
        solve(root->left, val, cur + 1, depth);
        solve(root->right, val, cur + 1, depth);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        solve(root, val, 1, depth);
        return root;
    }
};

int main()
{
    return 0;
}