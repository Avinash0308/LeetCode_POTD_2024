#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ans = 0;
        long long cnt = 0;
        for (auto i : s)
        {
            if (i == '0')
                ans += cnt;
            else
                cnt++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}