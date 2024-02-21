#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0;
        int cur = 0;
        int val = right;
        for (int i = 0; i < 31; i++)
        {
            int shift = 1 << i;
            if (right & shift)
            {
                int num = val - shift;
                if (num < left)
                {
                        ans += shift;
                }
            }
            val = val | shift;
        }
        return ans;
    }
};