#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long int> v(32);
        int start = -1;
        long long int orr = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            orr |= nums[i];
            long long int val = 1;
            for (int j = 0; j < 32; j++)
            {
                if (val & nums[i])
                    v[j]++;
                val <<= 1;
            }
            if (orr >= k)
            {
                ans = min(ans, i - start);
                while (start + 1 < i && orr >= k)
                {
                    long long int value = 1;
                    for (int j = 0; j < 32; j++)
                    {
                        if (value & nums[start + 1])
                        {
                            v[j]--;
                            if (v[j] == 0)
                            {
                                orr -= value;
                            }
                        }
                        value <<= 1;
                    }
                    if (orr >= k)
                    {
                        ans = min(ans, i - start - 1);
                    }
                    start++;
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};

int main()
{
    return 0;
}