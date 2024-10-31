#include <bits/stdc++.h>
using namespace std;

#define INT_MAX 1e12 + 7
class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        long long int n = robot.size(), m = factory.size();
        vector<vector<long long int>> dp(n, vector<long long int>(m, INT_MAX));
        for (long long int i = 0; i < m; i++)
        {
            for (long long int j = 0; j < n; j++)
            {
                long long int cur = INT_MAX;
                if (i)
                    cur = dp[j][i - 1];
                long long int dist = 0;
                for (long long int k = j; k >= 0; k--)
                {
                    if (j - k + 1 > factory[i][1])
                        break;
                    dist += abs(factory[i][0] - robot[k]);
                    if (k)
                    {
                        if (i == 0 || dp[k - 1][i - 1] == INT_MAX)
                            continue;
                        cur = min(cur, dp[k - 1][i - 1] + dist);
                    }
                    else
                    {
                        cur = min(cur, dist);
                    }
                }
                dp[j][i] = cur;
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    return 0;
}