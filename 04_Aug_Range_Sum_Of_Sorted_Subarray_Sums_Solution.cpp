#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int cur = 0;
            for(int j = i; j<n; j++){
                cur += nums[j];
                ans.push_back(cur);
            }
        }
        sort(ans.begin(),ans.end());
        long long int res = 0, mod = 1e9+7;
        for(int i = left-1; i<right; i++){
            res = (res + ans[i])%mod;
        }
        return res;
    }
};

int main(){
    return 0;
}