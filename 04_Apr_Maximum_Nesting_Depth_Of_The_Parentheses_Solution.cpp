#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int cur = 0;
        for (auto c : s)
        {
            if (c == '(')
                ans++;
            else if (c == ')')
                ans--;
            cur = max(cur, ans);
        }
        return cur;
    }
};

int main()
{
    return 0;
}