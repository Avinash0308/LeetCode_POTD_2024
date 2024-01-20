#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int x, int y, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (x >= n)
            return 0;
        if (x < 0 || x >= n || y < 0 || y >= m)
            return INT_MAX;
        if (dp[x][y] != INT_MAX)
            return dp[x][y];
        int a = solve(x + 1, y - 1, n, m, matrix, dp);
        int b = solve(x + 1, y, n, m, matrix, dp);
        int c = solve(x + 1, y + 1, n, m, matrix, dp);
        return dp[x][y] = matrix[x][y] + min({a, b, c});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, solve(0, i, n, m, matrix, dp));
        }
        return ans;
    }
};