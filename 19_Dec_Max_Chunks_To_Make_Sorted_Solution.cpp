#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        priority_queue<int> pq;
        int ans = 0;
        for(auto i:arr){
            pq.push(i);
            if(pq.top() == pq.size() - 1) ans++;
        }
        return ans;
    }
};
int main(){
    return 0;
}