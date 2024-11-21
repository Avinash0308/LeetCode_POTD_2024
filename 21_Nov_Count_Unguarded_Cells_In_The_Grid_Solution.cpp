#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int x, int y, int n, int m, vector<vector<int>> &v){
        if(x < 0 || x>=n || y<0 || y>=m || v[x][y] == 1 || v[x][y] == 2) return 0;
        else return 1;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> v(m,vector<int>(n,0));
        for(auto i:guards){
            v[i[0]][i[1]] = 1;
        }
        for(auto i:walls){
            v[i[0]][i[1]] = 2;
        }
        vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
        queue<vector<int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(v[i][j] == 1){
                    for(int x = 0; x<4; x++){
                        q.push({i+dir[x][0],j+dir[x][1],x});
                    }
                }
            }
        }

        while(!q.empty()){
            int x = q.front()[0], y = q.front()[1];
            int k = q.front()[2];
            q.pop();
            if(check(x,y,m,n,v)){
                v[x][y] = 3;
                q.push({x+dir[k][0],y+dir[k][1],k});
            }
        }

        int ans =0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(v[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};
int main(){
  return 0;
}
