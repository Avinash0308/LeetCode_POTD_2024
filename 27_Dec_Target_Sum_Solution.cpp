#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, vector<int> &nums, int rem, vector<unordered_map<int,int>> &dp){
        if(ind == nums.size()){
            return rem == 0;
        }
        if(dp[ind].count(rem)) return dp[ind][rem];
        return dp[ind][rem] = solve(ind+1,nums,rem-nums[ind],dp) + solve(ind+1,nums,rem+nums[ind],dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        return solve(0,nums,target,dp);
    }
};

int main(){
    return 0;
}