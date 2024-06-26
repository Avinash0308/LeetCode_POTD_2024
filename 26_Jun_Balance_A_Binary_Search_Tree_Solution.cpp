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
    void get_tree(TreeNode *root, vector<int> &tree)
    {
        if (!root)
            return;
        get_tree(root->left, tree);
        tree.push_back(root->val);
        get_tree(root->right, tree);
    }
    TreeNode *arrange(vector<int> &tree, int low, int high)
    {
        if (low > high)
            return NULL;
        int mid = (low + high) / 2;
        TreeNode *cur = new TreeNode(tree[mid]);
        cur->left = arrange(tree, low, mid - 1);
        cur->right = arrange(tree, mid + 1, high);
        return cur;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> tree;
        get_tree(root, tree);
        int n = tree.size();
        return arrange(tree, 0, n - 1);
    }
};

int main()
{
    return 0;
}