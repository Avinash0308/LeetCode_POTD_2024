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
    void solve(int sum, int &ans, TreeNode *root)
    {
        if (!root)
            return;
        sum = sum * 10 + root->val;
        if (!(root->left) && !(root->right))
            ans += sum;
        else
        {
            solve(sum, ans, root->left);
            solve(sum, ans, root->right);
        }
    }
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        solve(0, ans, root);
        return ans;
    }
};

int main()
{
    return 0;
}