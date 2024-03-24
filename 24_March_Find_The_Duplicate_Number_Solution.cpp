#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int mod = n + 1;
        for (int i = 0; i < n; i++)
        {
            nums[nums[i] % mod] += mod;
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] / mod > 1)
                ans = i;
            nums[i] %= mod;
        }
        return ans;
    }
};

int main()
{
    return 0;
}