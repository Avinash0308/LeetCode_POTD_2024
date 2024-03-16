#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int cnt_one = 0, cnt_zero = 0;
        int i = 0;
        for (auto val : nums)
        {
            if (val)
                cnt_one++;
            else
                cnt_zero++;
            int diff = cnt_one - cnt_zero;
            if (mp.find(diff) == 0)
            {
                mp[diff] = i;
            }
            else
            {
                ans = max(ans, i - mp[diff]);
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}