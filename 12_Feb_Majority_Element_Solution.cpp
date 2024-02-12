#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ele = 0, cnt = 0;
        for (auto val : nums)
        {
            if (val == ele)
                cnt++;
            else
            {
                if (cnt <= 1)
                {
                    cnt = 1;
                    ele = val;
                }
                else
                {
                    cnt--;
                }
            }
        }
        return ele;
    }
};