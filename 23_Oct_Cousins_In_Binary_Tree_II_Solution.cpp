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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (!root)
            return root;
        int sum = root->val;
        root->val = -root->val;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size(), cur = 0;
            while (len--)
            {
                TreeNode *h = q.front();
                q.pop();
                h->val += sum;
                int child = 0;
                if (h->left)
                    child += h->left->val;
                if (h->right)
                    child += h->right->val;
                if (h->left)
                    h->left->val = -child;
                if (h->right)
                    h->right->val = -child;
                if (h->left)
                    q.push(h->left);
                if (h->right)
                    q.push(h->right);
                cur += child;
            }
            sum = cur;
        }
        return root;
    }
};

int main()
{
    return 0;
}