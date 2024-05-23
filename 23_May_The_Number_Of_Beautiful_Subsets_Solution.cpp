#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, int &ans, vector<int> &nums, int k, unordered_map<int, int> &mp)
    {
        int n = nums.size();
        if (ind == n)
        {
            ans++;
            return;
        }
        solve(ind + 1, ans, nums, k, mp);
        if (mp[nums[ind]] == 0)
        {
            mp[nums[ind] - k]++;
            mp[nums[ind] + k]++;
            solve(ind + 1, ans, nums, k, mp);
            mp[nums[ind] - k]--;
            mp[nums[ind] + k]--;
        }
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        solve(0, ans, nums, k, mp);
        return ans - 1;
    }
};

int main()
{
    return 0;
}