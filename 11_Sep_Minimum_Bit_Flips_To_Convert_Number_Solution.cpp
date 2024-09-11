#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int ans = 0;
        int val = 1;
        for (int i = 0; i < 31; i++)
        {
            int x = start & val;
            int y = goal & val;
            if (x != y)
                ans++;
            val <<= 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}