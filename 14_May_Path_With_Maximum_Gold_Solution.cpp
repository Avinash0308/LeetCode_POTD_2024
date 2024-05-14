#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        int maxy = max({solve(i-1,j,n,m,grid),solve(i,j+1,n,m,grid),solve(i+1,j,n,m,grid),solve(i,j-1,n,m,grid)});
        grid[i][j] = val;
        return val + maxy;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]) ans = max(ans,solve(i,j,n,m,grid));
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}