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
    int ans = 0;
    int solve(TreeNode *root, int start, int lat)
    {
        if (!root)
            return lat;
        if (start == root->val)
        {
            lat = 0;
            solve(root->left, start, 1);
            solve(root->right, start, 1);
            return 1;
        }
        else if (lat == -1)
        {
            int a = solve(root->left, start, lat);
            if (a != -1)
            {
                ans = max(ans, a);
                lat = a + 1;
            }
            int b = solve(root->right, start, lat);
            if (a == -1 && b != -1)
            {
                solve(root->left, start, b + 1);
                ans = max(ans, b);
                lat = b + 1;
            }
            return lat;
        }
        else
        {
            ans = max(ans, lat);
            solve(root->left, start, lat + 1);
            solve(root->right, start, lat + 1);
            return 0;
        }
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        solve(root, start, -1);
        return ans;
    }
};