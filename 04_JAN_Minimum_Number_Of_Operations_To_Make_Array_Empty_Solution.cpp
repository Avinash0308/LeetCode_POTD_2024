#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int ans = 0;
        for(auto it:m){
            int val = it.second;
            if(val == 1) return -1;
            if(val%3) ans++;
            ans += val/3;
        }
        return ans;
    }
};