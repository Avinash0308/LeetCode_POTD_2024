#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, long long int p)
    {
        unordered_map<long long int, int> mp;
        long long int sum = 0;
        for (auto i : nums)
        {
            sum = sum + i;
        }
        mp[0] = -1;
        long long int cur = 0;
        long long int n = nums.size();
        long long int ans = n;
        for (long long int i = 0; i < n; i++)
        {
            cur += nums[i];
            mp[cur % p] = i;
            long long int val = (sum - cur) % p;
            if (mp.count((p - val) % p) != 0)
            {
                ans = min(ans, i - mp[(p - val) % p]);
            }
        }
        if (ans == n)
            return -1;
        return ans;
    }
};

int main()
{
    return 0;
}