#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            int a = 0, b = 0;
            while (i < n && (s[i] == 'a' || s[i] == 'b'))
            {
                if (s[i] == 'a')
                {
                    if (x <= y)
                    {
                        if (b)
                        {
                            ans += y;
                            b--;
                        }
                        else
                            a++;
                    }
                    else
                        a++;
                }
                else
                {
                    if (x >= y)
                    {
                        if (a)
                        {
                            ans += x;
                            a--;
                        }
                        else
                            b++;
                    }
                    else
                        b++;
                }
                i++;
            }
            ans += min(a, b) * min(x, y);
        }
        return ans;
    }
};

int main()
{
    return 0;
}