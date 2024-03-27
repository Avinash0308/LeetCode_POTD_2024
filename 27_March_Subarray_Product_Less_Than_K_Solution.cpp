#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int cur = 1;
        int n = nums.size();
        int start = -1;
        for(int i = 0; i<n; i++){
            cur *= nums[i];
            while(start < i && cur >= k){
                cur/=nums[start+1];
                start++;
            }
            count += (i-start);
        }
        return count;
    }
};

int main(){
    return 0;
}