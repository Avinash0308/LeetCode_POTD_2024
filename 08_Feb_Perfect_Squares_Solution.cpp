#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int sq = sqrt(i);
            if (sq * sq == i)
            {
                v[i] = 1;
                continue;
            }
            int start = 1, end = i - 1, val = INT_MAX;
            while (start <= end)
            {
                val = min(val, v[start] + v[end]);
                start++;
                end--;
            }
            v[i] = val;
        }
        return v[n];
    }
};