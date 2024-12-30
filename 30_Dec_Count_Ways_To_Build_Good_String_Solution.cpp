#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int solve(int cur, int zero, int one, int low, int high, vector<int> &dp)
    {
        if (cur > high)
            return 0;
        if (dp[cur] != -1)
            return dp[cur];
        return dp[cur] = ((low <= cur && cur <= high) + solve(cur + zero, zero, one, low, high, dp) + solve(cur + one, zero, one, low, high, dp)) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, -1);
        return solve(0, zero, one, low, high, dp);
    }
};

int main()
{
    return 0;
}