#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long int val = c;
        for (long long int i = 0; 2 * (i * i) <= c; i++)
        {
            long long int j = val - (i * i);
            long long int x = sqrt(j);
            if (x * x == j)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}