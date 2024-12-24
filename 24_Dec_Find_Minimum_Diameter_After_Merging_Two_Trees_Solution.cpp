#include<bits/stdc++.h>
using namespace std;

class Solution {
    int res;
public:
    int solve(unordered_map<int,vector<int>> &mp, unordered_map<int,int> &vis, int ind, int &ans){
        if(vis.count(ind)) return 0;
        vis[ind] = 1;
        int ans1 =0 ,ans2 = 0;
        for(auto i:mp[ind]){
            int val = solve(mp,vis,i,ans);
            if(ans1 <= val){
                ans2 = ans1;
                ans1 = val;
            }
            else if(ans2 < val){
                ans2 = val;
            }
        }
        ans = max(ans,(ans1+ans2+1)/2);
        res = max(res,ans1+ans2);
        return max(ans1,ans2) + 1;
    }
    int find(unordered_map<int,vector<int>> &mp){
        if(mp.empty()) return 0;
        unordered_map<int,int> vis;
        int ans = 0;
        cout<<solve(mp,vis,0, ans)<<" "<<ans<<endl;
        return ans;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        res = 0;
        unordered_map<int,vector<int>> a, b;
        for(auto i:edges1){
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        for(auto i:edges2){
            b[i[0]].push_back(i[1]);
            b[i[1]].push_back(i[0]);
        }
        int x = find(a);
        int y = find(b);
        cout<<x<<" "<<y<<endl;
        res = max(res,x+y+1);
        return res;
    }
};

int main(){
    return 0;
}