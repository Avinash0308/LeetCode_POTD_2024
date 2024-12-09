#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2)
            {
                dp[i]++;
            }
        }
        vector<bool> ans;
        for (auto i : queries)
        {
            if (dp[i[0]] == dp[i[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};

int main()
{
    return 0;
}