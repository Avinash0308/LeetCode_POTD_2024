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
public:
    void findleaves(TreeNode* a, vector<int> &v){
        if(!a) return ;
        if(!(a->left) && !(a->right)) v.push_back(a->val);
        findleaves(a->left,v);
        findleaves(a->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        findleaves(root1,a);
        findleaves(root2,b);
        return a== b;
    }
};