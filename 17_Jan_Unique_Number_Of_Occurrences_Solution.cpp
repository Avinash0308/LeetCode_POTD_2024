#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr) m[i]++;
        unordered_map<int,int> count;
        for(auto i:m){
            if(count.count(i.second)) return false;
            count[i.second]++;
        }
        return true;
    }
};