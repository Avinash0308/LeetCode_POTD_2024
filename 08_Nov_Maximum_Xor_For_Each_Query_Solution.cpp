#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        ll maxi = 1 << maximumBit;
        int n = nums.size();
        vector<int> ans(n);
        vector<int> bits(30);
        for (int i = 0; i < n; i++)
        {
            ll val = 1;
            for (int j = 0; j < 30; j++)
            {
                if (val & nums[i])
                    bits[j]++;
                val <<= 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ll cur = 0;
            ll val = 1 << 29;
            ll sum = 0;
            for (int j = 29; j >= 0; j--)
            {
                if (bits[j] % 2)
                    sum += val;
                else
                {
                    if (cur + val < maxi)
                    {
                        cur += val;
                        sum += val;
                    }
                }
                bits[j] -= ((val & nums[n - i - 1]) != 0);
                val >>= 1;
            }
            ans[i] = cur;
        }
        return ans;
    }
};

int main()
{
    return 0;
}