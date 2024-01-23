#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<string> &arr, int &ans, int cur, vector<int> vis, int ind)
    {
        int n = arr.size();
        if (ind >= n)
        {
            ans = max(ans, cur);
            return;
        }
        solve(arr, ans, cur, vis, ind + 1);
        for (auto i : arr[ind])
        {
            if (vis[i - 'a'])
                return;
            vis[i - 'a'] = 1;
        }
        cur += arr[ind].size();
        solve(arr, ans, cur, vis, ind + 1);
    }
    int maxLength(vector<string> &arr)
    {
        int ans = 0;
        int cur = 0;
        vector<int> vis(26);
        solve(arr, ans, cur, vis, 0);
        return ans;
    }
};