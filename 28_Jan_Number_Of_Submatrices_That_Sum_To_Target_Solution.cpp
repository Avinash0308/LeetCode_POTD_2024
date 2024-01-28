#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < m; j++)
            {
                cur += matrix[i][j];
                if (i != 0)
                {
                    dp[i][j] = dp[i - 1][j] + cur;
                }
                else
                    dp[i][j] = cur;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int x = 0; x <= i; x++)
                {
                    for (int y = 0; y <= j; y++)
                    {
                        int val = dp[i][j];
                        if (x > 0)
                            val -= dp[x - 1][j];
                        if (y > 0)
                            val -= dp[i][y - 1];
                        if (x > 0 && y > 0)
                            val += dp[x - 1][y - 1];
                        if (val == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};