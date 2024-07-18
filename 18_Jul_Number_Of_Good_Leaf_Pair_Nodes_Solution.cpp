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
    vector<int> solve(TreeNode *root, int dis, int &ans)
    {
        if (!root)
            return {};
        if (!root->left && !root->right)
        {
            return {1};
        }
        vector<int> l = solve(root->left, dis, ans);
        vector<int> r = solve(root->right, dis, ans);
        vector<int> fin;
        for (int i = 0; i < l.size(); i++)
        {
            for (int j = 0; j < r.size(); j++)
            {
                if (l[i] + r[j] <= dis)
                {
                    ans++;
                }
            }
        }
        for (int i = 0; i < l.size(); i++)
        {
            fin.push_back(l[i] + 1);
        }
        for (int i = 0; i < r.size(); i++)
        {
            fin.push_back(r[i] + 1);
        }
        return fin;
    }
    int countPairs(TreeNode *root, int distance)
    {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};

int main()
{
    TreeNode *start = new TreeNode(1);
    start->left = new TreeNode(2);
    start->right = new TreeNode(3);
    start->left->left = new TreeNode(4);
    start->left->right = new TreeNode(5);
    start->right->left = new TreeNode(6);
    start->right->right = new TreeNode(7);
    return 0;
}