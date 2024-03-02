#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n);
        int neg = -1;
        while (neg < n - 1 && nums[neg + 1] < 0)
            neg++;
        int pos = neg + 1;
        int ind = 0;
        while (ind < n)
        {
            int val;
            if (pos == n || (neg >= 0 && abs(nums[neg]) < nums[pos]))
            {
                val = nums[neg] * nums[neg];
                neg--;
            }
            else
            {
                val = nums[pos] * nums[pos];
                pos++;
            }
            v[ind] = val;
            ind++;
        }
        nums = v;
        v.resize(0);
        return nums;
    }
};