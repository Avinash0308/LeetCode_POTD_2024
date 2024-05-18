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
    int solve(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        root->val += solve(root->left, ans);
        root->val += solve(root->right, ans);
        ans += abs(1 - root->val);
        return root->val - 1;
    }
    int distributeCoins(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

int main()
{
    return 0;
}