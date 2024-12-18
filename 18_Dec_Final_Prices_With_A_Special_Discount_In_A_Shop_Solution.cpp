#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        for(int i = prices.size()-1; i>=0; i--){
            int val = prices[i];
            while(!s.empty() && s.top() > val) s.pop();
            if(!s.empty()) prices[i] -= s.top();
            s.push(val);
        }
        return prices;
    }
};

int main(){
    return 0;
}