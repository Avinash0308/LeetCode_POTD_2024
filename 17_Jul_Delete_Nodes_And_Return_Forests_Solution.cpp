#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    void solve(TreeNode *&root, unordered_map<int, int> &mp, vector<TreeNode *> &ans, int parent)
    {
        if (!root)
            return;
        solve(root->left, mp, ans, root->val);
        solve(root->right, mp, ans, root->val);
        if (mp.count(root->val) != 0)
        {
            root = NULL;
        }
        else
        {
            if (mp.count(parent) != 0)
            {
                ans.push_back(root);
            }
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_map<int, int> mp;
        mp[-1] = 1;
        for (auto i : to_delete)
        {
            mp[i]++;
        }
        vector<TreeNode *> ans;
        solve(root, mp, ans, -1);
        return ans;
    }
};

int main()
{
    return 0;
}