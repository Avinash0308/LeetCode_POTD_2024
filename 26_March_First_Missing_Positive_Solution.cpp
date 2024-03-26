#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int mod = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0 || nums[i] > n)
                nums[i] = 0;
            mod = max(mod, nums[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % mod > 0 && nums[i] % mod <= n)
            {
                nums[(nums[i] % mod) - 1] += mod;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] / mod == 0)
                return i + 1;
        }
        return n + 1;
    }
};

int main()
{
    return 0;
}