#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int check(string &str){
        int val = 0;
        int i = 0, n = str.size();
        while(i<n){
            val = val*10 + str[i]-'0';
            if(val > 255) return 1;
            i++;
        }
        return 0;
    }
    int isValid(string str) {
        // code here
        int n = str.size(), count = 0;
        for(int i =0; i<n; i++){
            string cur = "";
            while(i<n && str[i] != '.'){
                cur += str[i];
                i++;
            }
            if(cur.empty() || check(cur)) return 0;
            count++;
        }
        return count == 4;
    }
};

int main(){
    return 0;
}