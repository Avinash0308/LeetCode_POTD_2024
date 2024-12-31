#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n);
        for(int i = n-1; i>=0; i--){
            int a = costs[0], b = costs[1], c = costs[2];
            if(i+1 < n) a += dp[i+1];

            int j = i+1;
            while(j<n && days[j] < days[i] + 7) j++;
            if(j < n) b += dp[j];

            j = i+1;
            while(j < n && days[j] < days[i] + 30) j++;
            if(j<n) c += dp[j];
            dp[i] = min({a,b,c});
        }
        return dp[0];
    }
};
int main(){
    return 0;
}