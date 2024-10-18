#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, int cur, vector<int> &nums, int req, int &ans)
    {
        if (ind == nums.size())
        {
            if (cur == req)
                ans++;
            return;
        }
        solve(ind + 1, cur, nums, req, ans);
        solve(ind + 1, cur | nums[ind], nums, req, ans);
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int req = 0;
        for (auto i : nums)
            req |= i;
        int ans = 0;
        solve(0, 0, nums, req, ans);
        return ans;
    }
};

int main()
{
    return 0;
}