#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return 0;
        int ind = 1;
        int one = 0;
        for (int i = 0; i < 32; i++)
        {
            if (ind & n)
                one++;
            ind <<= 1;
        }
        return one == 1;
    }
};