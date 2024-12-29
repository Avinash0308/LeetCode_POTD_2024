#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long int mod = 1e9 + 7;
public:
    long long int solve(long long int ind1, long long int ind2, vector<vector<long long int>> &v, string &target, vector<vector<long long int>> &pre){
        long long int n = v[0].size(), m = target.size();
        if(ind2 == m) return 1;
        if(ind1 == n) return 0;
        if(pre[ind1][ind2] != -1) return pre[ind1][ind2];
        long long int ans = solve(ind1+1, ind2, v, target, pre);
        if(v[target[ind2]-'a'][ind1]){
            ans = (ans + (v[target[ind2]-'a'][ind1]*solve(ind1+1,ind2+1,v,target,pre))%mod)%mod;
        }
        return pre[ind1][ind2] = ans;
    }
    long long int numWays(vector<string>& words, string target) {
        long long int n = words[0].size();
        long long int m = target.size();
        vector<vector<long long int>> v(26, vector<long long int>(n, 0));
        for(long long int i = 0; i<words.size(); i++){
            for(long long int j = 0; j<n; j++){
                v[words[i][j]-'a'][j]++;
            }
        }
        vector<vector<long long int>> pre(n, vector<long long int>(m, -1));
        return solve(0, 0, v, target, pre);
    }
};
int main(){
    return 0;
}