#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        int x = 0, y = 0, z = 0;
        while (a || b || c)
        {
            if (a >= b && a >= c)
            {
                if (x == 2)
                {
                    if (b == 0 && c == 0)
                        break;
                    else if (b >= c)
                    {
                        y = 1;
                        x = z = 0;
                        b--;
                        ans += 'b';
                    }
                    else
                    {
                        z = 1;
                        x = y = 0;
                        c--;
                        ans += 'c';
                    }
                }
                else
                {
                    x++;
                    y = z = 0;
                    a--;
                    ans += 'a';
                }
            }
            else if (b >= a && b >= c)
            {
                if (y == 2)
                {
                    if (a == 0 && c == 0)
                        break;
                    else if (a >= c)
                    {
                        x = 1;
                        y = z = 0;
                        a--;
                        ans += 'a';
                    }
                    else
                    {
                        z = 1;
                        x = y = 0;
                        c--;
                        ans += 'c';
                    }
                }
                else
                {
                    y++;
                    x = z = 0;
                    b--;
                    ans += 'b';
                }
            }
            else
            {
                if (z == 2)
                {
                    if (a == 0 && b == 0)
                        break;
                    else if (a >= b)
                    {
                        x = 1;
                        y = z = 0;
                        a--;
                        ans += 'a';
                    }
                    else
                    {
                        y = 1;
                        x = z = 0;
                        b--;
                        ans += 'b';
                    }
                }
                else
                {
                    z++;
                    x = y = 0;
                    c--;
                    ans += 'c';
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}