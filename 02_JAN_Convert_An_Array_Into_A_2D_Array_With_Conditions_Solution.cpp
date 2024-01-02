#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxy = 0;
        for(auto it:nums){
            m[it]++;
            maxy = max(maxy,m[it]);
        }
        vector<vector<int>> ans(maxy);
        for(auto it:m){
            int val = it.second;
            while(val){
                ans[val-1].push_back(it.first);
                val--;
            }
        }
        return ans;
    }
};