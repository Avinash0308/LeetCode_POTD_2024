#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        int cur = 0;
        sort(items.begin(),items.end());
        for(int i = 0; i<n; i++){
            cur = max(cur,items[i][1]);
            items[i][1] = cur;
        }
        vector<int> ans(m);
        for(int i = 0; i<m; i++){
            int val = queries[i];
            int res = 0;
            int low = 0, high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(items[mid][0] > val) high = mid-1;
                else{
                    res = max(res,items[mid][1]);
                    low = mid+1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};
int main(){
  return 0;
}
