#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int a = 0, b = 0, c = 0;
        for (auto i : bills)
        {
            if (i == 5)
            {
                a++;
            }
            else if (i == 10)
            {
                if (a)
                {
                    a--;
                    b++;
                }
                else
                    return false;
            }
            else
            {
                if (a && b)
                {
                    a--;
                    b--;
                    c++;
                }
                else if (a >= 3)
                {
                    a -= 3;
                    c++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}