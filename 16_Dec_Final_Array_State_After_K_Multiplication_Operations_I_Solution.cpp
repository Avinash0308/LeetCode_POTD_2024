#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i = 0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }
        while(k--){
            vector<int> cur = pq.top();
            pq.pop();
            pq.push({cur[0]*multiplier,cur[1]});
        }
        while(!pq.empty()){
            nums[pq.top()[1]] = pq.top()[0];
            pq.pop();
        }
        return nums;
    }
};

int main(){
    return 0;
}