#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> a(n), b(n);
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
                x++;
            if (s[n - i - 1] == 'a')
                y++;
            a[i] = x, b[n - i - 1] = y;
        }
        int ans = min(a[n - 1], b[0]), last = n;
        for (int i = n - 1; i >= 0; i--)
        {
            int val = a[i] + ((last != n) ? b[last] : 0);
            ans = min(ans, val);
            if (s[i] == 'b')
                last = i;
        }
        return ans;
    }
};

int main()
{
    return 0;
}