#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int ans = 0;
        int start = -1;
        int n = nums.size();
        unordered_map<int, int> mp;
        set<int> s;
        unordered_map<int, int> lo;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] == 1)
            {
                s.insert(i);
            }
            else
            {
                s.erase(lo[nums[i]]);
                s.insert(i);
            }
            lo[nums[i]] = i;
            if (mp.size() > k)
            {
                int ind = *(s.begin());
                while (start < ind)
                {
                    if (mp[nums[start + 1]] == 1)
                    {
                        mp.erase(nums[start + 1]);
                    }
                    else
                    {
                        mp[nums[start + 1]]--;
                    }
                    start++;
                }
                lo.erase(nums[start]);
                s.erase(ind);
            }
            if (mp.size() == k)
            {
                int ind = *(s.begin());
                ans += ind - start;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}