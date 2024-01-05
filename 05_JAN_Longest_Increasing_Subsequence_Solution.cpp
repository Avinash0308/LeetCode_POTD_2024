#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ansy = 0;
        vector<int> dp(n);
        for(int i= n-1; i>=0; i--){
            int ans = 0;
            for(int j = i+1; j<n; j++){
                if(nums[j] > nums[i]) ans = max(ans,dp[j]);
            }
            dp[i] = ans+1;
            ansy = max(ansy,dp[i]);
        }
        return ansy;
    }
};