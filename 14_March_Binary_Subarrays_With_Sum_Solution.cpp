#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        queue<int> one;
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                cur++;
            }
            else
            {
                one.push(cur);
                cur = 0;
            }
            if (goal == 0)
                ans += cur;
            if (goal < one.size())
                one.pop();
            if (goal && goal == one.size())
                ans += (one.front() + 1);
        }
        return ans;
    }
};