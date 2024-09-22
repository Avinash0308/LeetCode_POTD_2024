#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int count(long long int val, long long int n)
    {
        long long int cur = val, next = val + 1;
        long long int tot = 0;
        while (cur <= n)
        {
            tot += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return tot;
    }
    int findKthNumber(long long int n, long long int k, long long int start = 1)
    {
        k--;
        long long int val = 1;
        while (k > 0)
        {
            long long int cnt = count(val, n);
            if (k >= cnt)
            {
                k -= cnt;
                val++;
            }
            else
            {
                val *= 10;
                k--;
            }
        }
        return val;
    }
};

int main()
{
    return 0;
}