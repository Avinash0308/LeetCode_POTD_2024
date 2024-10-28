#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = sqrt(nums[i]);
            if (val * val == nums[i])
            {
                if (mp.count(val) != 0)
                {
                    mp[nums[i]] = mp[val] + 1;
                    ans = max(ans, mp[nums[i]]);
                }
                else
                {
                    mp[nums[i]] = 1;
                }
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }
        if (ans <= 1)
            return -1;
        else
            return ans;
    }
};

int main()
{
    return 0;
}