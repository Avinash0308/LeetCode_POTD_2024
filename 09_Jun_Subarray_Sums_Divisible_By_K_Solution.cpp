#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<long long, long long int> mp;
        long long int cur = 1e9 + 7;
        mp[cur % k] = 1;
        long long int ans = 0;
        for (auto i : nums)
        {
            cur += i;
            if (mp.count(cur % k) != 0)
                ans += mp[cur % k];
            mp[cur % k]++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}