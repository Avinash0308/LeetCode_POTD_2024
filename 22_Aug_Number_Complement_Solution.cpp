#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < 31; i++)
        {
            int val = 1 << i;
            if (num & val)
            {
                ans += cur;
                cur = 0;
            }
            else
            {
                cur += val;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}