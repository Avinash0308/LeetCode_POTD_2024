#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur += nums[i];
            if (cur % k == 0 && i + 1 >= 2)
                return true;
            if (cur % k)
            {
                if (mp.count(cur % k) != 0 && i - mp[cur % k] >= 2)
                    return true;
            }
            if (mp.count(cur % k) == 0)
                mp[cur % k] = i;
        }
        return false;
    }
};

int main()
{
    return 0;
}