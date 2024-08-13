#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int sum, int target, int ind, int n, vector<int> &a, vector<int> &v, vector<vector<int>> &ans)
    {
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }
        if (ind == n)
            return;
        if (sum + a[ind] <= target)
        {
            v.push_back(a[ind]);
            solve(sum + a[ind], target, ind + 1, n, a, v, ans);
            v.pop_back();
        }
        while (ind + 1 < n && a[ind] == a[ind + 1])
            ind++;
        solve(sum, target, ind + 1, n, a, v, ans);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, target, 0, n, candidates, cur, ans);
        return ans;
    }
};

int main()
{
    return 0;
}