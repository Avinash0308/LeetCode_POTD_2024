#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};