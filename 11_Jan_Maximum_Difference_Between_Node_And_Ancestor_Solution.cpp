#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans = 0;
public:
    pair<int,int> solve(TreeNode* root){
        if(!root) return {-1,-1};
        pair<int,int> a = solve(root->left);
        pair<int,int> b = solve(root->right);
        int p = (a.first == -1)?root->val:a.first;
        int q = (a.second == -1)?root->val:a.second;
        int r = (b.first == -1)?root->val:b.first;
        int s = (b.second == -1)?root->val:b.second;
        int val = root->val;
        ans = max({ans,val-p,q-val,val-r,s-val});
        return {min({val,p,q,r,s}),max({val,p,q,r,s})};
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};