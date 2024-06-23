#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        set<pair<int, int>> m;
        int start = 0, ans = 0, len = nums.size();
        for (int i = 0; i < len; i++)
        {
            m.insert({nums[i], i});
            auto it1 = m.begin();
            auto it2 = m.rbegin();
            while ((*it2).first - (*it1).first > limit)
            {
                m.erase({nums[start], start});
                start++;
                it1 = m.begin();
                it2 = m.rbegin();
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}