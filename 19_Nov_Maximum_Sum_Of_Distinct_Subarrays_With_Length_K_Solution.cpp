#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans = 0, cur = 0, ind = -1, n = nums.size();
        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++)
        {
            cur += nums[i];
            if (mp.count(nums[i]))
            {
                int limit = mp[nums[i]];
                while (ind < limit)
                {
                    cur -= nums[ind + 1];
                    mp.erase(nums[ind + 1]);
                    ind++;
                }
            }
            mp[nums[i]] = i;
            if (i - ind > k)
            {
                cur -= nums[ind + 1];
                mp.erase(nums[ind + 1]);
                ind++;
            }
            if (i - ind == k)
            {
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}