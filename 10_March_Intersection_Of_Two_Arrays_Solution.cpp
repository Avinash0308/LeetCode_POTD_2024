#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto i : nums1)
        {
            mp[i] = 1;
        }
        for (auto i : nums2)
        {
            if (mp.count(i) != 0)
            {
                ans.push_back(i);
                mp.erase(i);
            }
        }
        return ans;
    }
};