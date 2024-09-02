#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int a=accumulate(chalk.begin(),chalk.end(),0ll);
        k%=a;
        for(int i=0;i<chalk.size();i++){

             k -=chalk[i];
             if(k<0) return i;
        }
        return -1;
    }
};
int main(){
  return 0;
}
