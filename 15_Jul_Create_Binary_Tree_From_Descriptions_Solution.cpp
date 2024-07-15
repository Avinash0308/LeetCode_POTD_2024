#include <bits/stdc++.h>
using namespace std;

/**
Definition for a binary tree node.
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> mp;
        unordered_map<int, int> parent;
        for (auto i : descriptions)
        {
            TreeNode *cur, *child;
            if (mp.count(i[0]) != 0)
            {
                cur = mp[i[0]];
            }
            else
            {
                cur = new TreeNode(i[0]);
                mp[i[0]] = cur;
            }
            if (mp.count(i[1]) != 0)
            {
                child = mp[i[1]];
            }
            else
            {
                child = new TreeNode(i[1]);
                mp[i[1]] = child;
            }
            if (i[2])
                cur->left = child;
            else
                cur->right = child;
            parent[i[1]] = i[0];
        }
        for (auto i : mp)
        {
            if (parent.count(i.first) == 0)
                return i.second;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}