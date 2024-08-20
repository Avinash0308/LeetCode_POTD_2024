#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> solve(int ind, int m, vector<int> &piles, vector<vector<pair<int, int>>> &dp, int n)
    {
        if (dp[ind][m].first != -1)
            return dp[ind][m];
        for (int i = 0; i + ind < n && i < 2 * m; i++)
        {
            int a = piles[ind + i] - ((ind > 0) ? piles[ind - 1] : 0);
            int b = 0;
            if (i + ind + 1 < n)
            {
                pair<int, int> res = solve(i + ind + 1, min(n, max(m, i + 1)), piles, dp, n);
                a += res.second;
                b += res.first;
            }
            if (a > dp[ind][m].first)
            {
                dp[ind][m].first = a;
                dp[ind][m].second = b;
            }
        }
        return dp[ind][m];
    }
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        for (int i = 1; i < n; i++)
            piles[i] += piles[i - 1];
        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {-1, -1}));
        return solve(0, 1, piles, dp, n).first;
    }
};

int main()
{
    return 0;
}