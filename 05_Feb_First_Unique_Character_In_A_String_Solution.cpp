#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,0);
        vector<int> ind(26,-1);
        int i = 0;
        for(auto it:s){
            count[it-'a']++;
            ind[it-'a'] = i;
            i++;
        }
        int ans = INT_MAX;
        for(i = 0; i<26; i++){
            if(count[i] == 1) ans = min(ans,ind[i]); 
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};