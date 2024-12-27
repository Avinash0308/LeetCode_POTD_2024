#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int n = values.size();
        int cur = values[0]-1;
        for(int i = 1; i<n; i++){
            ans = max(ans,values[i]+cur);
            cur = max(cur-1,values[i]-1);
        }
        return ans;
    }
};
int main(){
    return 0;
}