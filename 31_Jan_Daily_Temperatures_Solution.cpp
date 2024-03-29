#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};