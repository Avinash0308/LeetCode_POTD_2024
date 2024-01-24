#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int ans = 0;
    void solve(TreeNode *root, vector<int> &count)
    {
        if (!root)
            return;
        count[root->val]++;
        if (!(root->left) && !(root->right))
        {
            int odd = 0;
            for (int i = 0; i < 10; i++)
            {
                if (count[i] % 2)
                    odd++;
            }
            if (odd <= 1)
                ans++;
        }
        solve(root->left, count);
        solve(root->right, count);
        count[root->val]--;
        return;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> count(10);
        solve(root, count);
        return ans;
    }
};