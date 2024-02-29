#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
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
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty())
        {
            int n = q.size();
            int prev = (lvl % 2) ? INT_MAX : 0;
            while (n--)
            {
                TreeNode *val = q.front();
                q.pop();
                if (val->val % 2 == lvl % 2)
                    return false;
                if (lvl % 2 && val->val >= prev)
                    return false;
                if (!(lvl % 2) && val->val <= prev)
                    return false;
                if (val->left)
                    q.push(val->left);
                if (val->right)
                    q.push(val->right);
                prev = val->val;
            }
            lvl++;
        }
        return true;
    }
};