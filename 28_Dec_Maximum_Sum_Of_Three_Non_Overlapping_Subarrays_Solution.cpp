#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n);
        int sum = 0;
        for(int i = n-1; i>=0; i--){
            sum += nums[i];
            if(n-i >= k){
                if(n-i > k) sum -= nums[i+k];
                v[i] = sum;
            }
            else v[i] = -1;
        }
        vector<int> x(n);
        int maxy = -1, ind = -1;
        for(int i = n-1; i>=0; i--){
            if(v[i] == -1) x[i] = -1;
            else{
                if(v[i] >= maxy){
                    maxy = v[i];
                    ind = i;
                }
                x[i] = ind;
            }
        }
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
        for(auto i:x) cout<<i<<" ";
        cout<<endl;
        vector<int> ans;
        maxy = -1;
        for(int i = 0; i<=n-(3*k); i++){
            for(int j = i+k; j<=n-(2*k); j++){
                int cur = v[i] + v[j] + v[x[j+k]];
                if(cur > maxy){
                    maxy = cur;
                    ans = {i, j, x[j+k]};
                    cout<<cur<<" "<<i<<" "<<j<<" "<<x[j+k]<<endl;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}