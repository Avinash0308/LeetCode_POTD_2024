#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > k)
            {
                while (start < i && mp[nums[i]] > k)
                {
                    mp[nums[start + 1]]--;
                    start++;
                }
            }
            ans = max(ans, i - start);
        }
        return ans;
    }
};

int main()
{
    return 0;
}