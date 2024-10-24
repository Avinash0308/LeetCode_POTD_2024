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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode *> q;
        if (!root)
            return -1;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            long long sum = 0;
            while (len--)
            {
                TreeNode *cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            pq.push(sum);
            if (pq.size() > k)
                pq.pop();
        }
        if (pq.size() < k)
            return -1;
        return pq.top();
    }
};

int main()
{
    return 0;
}