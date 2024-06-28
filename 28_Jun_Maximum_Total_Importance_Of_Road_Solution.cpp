#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> in(n);
        for(auto road:roads){
            in[road[0]]++;
            in[road[1]]++;
        }
        sort(in.begin(),in.end());
        long long ans = 0;
        for(long long int i = n-1; i>=0; i--){
            ans += (i+1)*in[i];
        }
        return ans;
    }
};

int main(){
    return 0;
}