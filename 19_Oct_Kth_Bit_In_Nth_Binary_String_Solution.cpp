#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';
        int len = (1 << n) - 1;
        int mid = (len / 2) + 1;
        if (mid == k)
            return '1';
        if (mid > k)
        {
            return findKthBit(n - 1, k);
        }
        else
        {
            char c = findKthBit(n - 1, 2 * mid - k);
            if (c == '0')
                return '1';
            else
                return '0';
        }
    }
};

int main()
{
    return 0;
}