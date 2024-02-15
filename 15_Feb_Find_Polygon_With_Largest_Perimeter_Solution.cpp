#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        long long ans = 0;
        long long cur = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            cur += nums[i];
            if (cur > nums[i + 1])
            {
                ans = cur + nums[i + 1];
            }
        }
        if (!ans)
            return -1;
        return ans;
    }
};