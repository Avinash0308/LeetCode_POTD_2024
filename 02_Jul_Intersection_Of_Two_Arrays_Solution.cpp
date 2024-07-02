#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        for (auto i : nums1)
        {
            mp[i]++;
        }
        vector<int> ans;
        for (auto i : nums2)
        {
            if (mp[i])
            {
                mp[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}