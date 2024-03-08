#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int maxy = 0, num = 0;
        unordered_map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
            if (mp[i] > maxy)
            {
                maxy = mp[i];
                num = 1;
            }
            else if (mp[i] == maxy)
            {
                num++;
            }
        }
        return maxy * num;
    }
};