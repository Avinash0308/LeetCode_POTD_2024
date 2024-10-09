#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int ans = 0, o = 0;
        for (auto i : s)
        {
            if (i == '(')
                o++;
            else
                o--;
            if (o < 0)
            {
                o = 0;
                ans++;
            }
        }
        ans += o;
        return ans;
    }
};

int main()
{
    return 0;
}