#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int one = 0, n = bank.size(), m = bank[0].size(), ans = 0;
        for(int i = 0; i<n; i++){
            int cur = 0;
            for(int j = 0; j<m; j++){
                if(bank[i][j] == '1') cur++;
            }
            if(cur){
                if(one){
                    ans += one*cur;
                }
                one = cur;
            }
        }
        return ans;
    }
};