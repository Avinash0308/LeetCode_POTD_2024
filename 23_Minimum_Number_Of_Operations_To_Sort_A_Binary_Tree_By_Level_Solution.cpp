#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return 0;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            int x = len;
            vector<int> idx(len);
            vector<int> arr;
            iota(idx.begin(),idx.end(),0);
            while(len--){
                arr.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            sort(idx.begin(),idx.end(), [&](int i, int j){
                return arr[i] < arr[j];
            });
            for(int i = 0; i<x;){
                int j= idx[i];
                if(j == i) i++;
                else{
                    ans++;
                    swap(idx[i],idx[j]);
                }
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}