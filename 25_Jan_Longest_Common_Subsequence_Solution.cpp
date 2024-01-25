#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind1, int ind2, string &text1, string &text2, map<pair<int,int>,int> &m){
        int n = text1.size(), m2 = text2.size();
        if(ind1 >= n || ind2 >= m2) return 0;
        if(m.count({ind1,ind2}) != 0) return m[{ind1,ind2}];
        if(text1[ind1] == text2[ind2]){
            return m[{ind1,ind2}] = 1 + solve(ind1+1,ind2+1,text1,text2,m);
        }
        else{
            return m[{ind1,ind2}] = max(solve(ind1+1,ind2,text1,text2,m) , solve(ind1,ind2+1,text1,text2,m));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        map<pair<int,int>,int> dp;
        return solve(0,0,text1,text2,dp);
    }
};