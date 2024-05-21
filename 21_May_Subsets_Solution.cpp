#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, vector<int> &cur, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (ind == nums.size())
        {
            ans.push_back(cur);
            return;
        }
        solve(ind + 1, cur, ans, nums);
        cur.push_back(nums[ind]);
        solve(ind + 1, cur, ans, nums);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(0, cur, ans, nums);
        return ans;
    }
};

int main()
{
    return 0;
}