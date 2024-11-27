#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, int prev, vector<int> &res, vector<vector<int>> &v)
    {
        if (res[ind] > res[prev] + 1)
        {
            res[ind] = res[prev] + 1;
            for (auto i : v[ind])
            {
                solve(i, ind, res, v);
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        int q = queries.size();
        vector<vector<int>> v(n);
        vector<int> res(n);
        vector<int> ans(q);
        for (int i = 0; i < n - 1; i++)
        {
            res[i] = n - 1 - i;
            v[i + 1].push_back(i);
        }
        for (int i = 0; i < q; i++)
        {
            int u = queries[i][0], x = queries[i][1];
            v[x].push_back(u);
            solve(u, x, res, v);
            ans[i] = res[0];
        }
        return ans;
    }
};

int main()
{
    return 0;
}