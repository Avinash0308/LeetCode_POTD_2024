#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        int ans = 0;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                n /= i;
                ans += i;
            }
        }
        if (n > 1)
            ans += n;
        return ans;
    }
};

int main()
{
    return 0;
}