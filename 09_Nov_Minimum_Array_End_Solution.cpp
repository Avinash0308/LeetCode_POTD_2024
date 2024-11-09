#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long ans = x;
        long long val = 1;
        long long check = n - 1, term = 1;
        for (int i = 0; i < 30; i++)
        {
            while (x & val)
                val <<= 1;
            if (check & term)
                ans += val;
            val <<= 1;
            term <<= 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}