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
    void solve(TreeNode *root, string &cur, string &ans)
    {
        if (!root)
            return;
        cur.push_back(char(root->val + 97));
        if (!(root->left) && !(root->right))
        {
            string x = cur;
            reverse(cur.begin(), cur.end());
            if (ans.empty() || ans > cur)
            {
                ans = cur;
            }
            cur = x;
        }
        solve(root->left, cur, ans);
        solve(root->right, cur, ans);
        cur.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string cur = "";
        string ans = "";
        solve(root, cur, ans);
        return ans;
    }
};

int main()
{
    return 0;
}