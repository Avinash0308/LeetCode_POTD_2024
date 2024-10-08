#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int end = n-1, ans = 0, o = 0, c = 0;
        for(int i = 0; i<end; i++){
            if(s[i] == '[') o++;
            else c++;
            if(c > o){
                o++;
                c--;
                ans++;
                while(s[end] != '[') end--;
                swap(s[i],s[end]);
            }
        }
        return ans;
    }
};

int main(){
  return 0;
}
