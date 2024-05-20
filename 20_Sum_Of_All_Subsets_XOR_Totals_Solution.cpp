#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int ind, int sum, int &ans, int n, vector<int> &nums)
    {
        if (n == ind)
        {
            ans += sum;
            return;
        }
        solve(ind + 1, sum, ans, n, nums);
        sum ^= nums[ind];
        solve(ind + 1, sum, ans, n, nums);
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        solve(0, 0, ans, n, nums);
        return ans;
    }
};

int main()
{
    return 0;
}