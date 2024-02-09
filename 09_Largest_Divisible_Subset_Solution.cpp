#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n);
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--)
        {
            int len = 0, ind = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] % nums[i] == 0 && len < dp[j].size())
                {
                    len = dp[j].size();
                    ind = j;
                }
            }
            if (len == 0)
                dp[i] = {nums[i]};
            else
            {
                vector<int> pre = dp[ind];
                pre.push_back(nums[i]);
                dp[i] = pre;
            }
        }
        int len = 0, ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i].size() > len)
            {
                len = dp[i].size();
                ind = i;
            }
        }
        return dp[ind];
    }
};