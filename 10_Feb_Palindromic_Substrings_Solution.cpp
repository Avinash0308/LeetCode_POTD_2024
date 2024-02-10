#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;
        vector<int> dp(n, 0);
        vector<int> cur(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] != s[j])
                {
                    cur[j] = 0;
                    continue;
                }
                if (j - i <= 1)
                    ans += (cur[j] = 1);
                else
                    ans += (cur[j] = dp[j - 1]);
            }
            dp = cur;
        }
        return ans;
    }
};