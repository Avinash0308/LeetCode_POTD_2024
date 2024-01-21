#include<bits/stdc++.h>
using  namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> col(3,0);
        for(int i = n-1; i>=0; i--){
            int cur = nums[i] + max(col[1],col[2]);
            col[2] = col[1];
            col[1] = col[0];
            col[0] = cur;
        }
        return max(col[1],col[0]);
    }
};