#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind, int n, int last, vector<int> &s, vector<int> &e, vector<int> &p, vector<int> &dp){
        if(ind >= n) return 0;
        if(last > s[ind]){
            int indd = lower_bound(s.begin(),s.end(),last) - s.begin();
            return solve(indd,n,last,s,e,p,dp);
        }
        if(dp[ind] != 0) return dp[ind];
        return dp[ind] = max(p[ind] + solve(ind+1,n,e[ind],s,e,p,dp),solve(ind+1,n,last,s,e,p,dp));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> v(n);
        for(int i = 0; i<n; i++){
            v[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(v.begin(),v.end());
        for(int i = 0; i<n; i++){
            startTime[i] = v[i][0];
            endTime[i] = v[i][1];
            profit[i] = v[i][2];
        }
        vector<int> dp(n);
        return solve(0,n,0,startTime,endTime,profit,dp);
    }
};