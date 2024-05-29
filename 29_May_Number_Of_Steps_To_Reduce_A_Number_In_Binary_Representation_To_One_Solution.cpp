#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int cur = 0, step = 0;
        int n = s.size();
        for (int i = n - 1; i > 0; i--)
        {
            if (s[i] == '1')
            {
                if (cur)
                {
                    step++;
                }
                else
                {
                    cur = 1;
                    step += 2;
                }
            }
            else
            {
                if (cur)
                {
                    step += 2;
                }
                else
                {
                    step += 1;
                }
            }
        }
        if (cur)
            return step + 1;
        else
            return step;
    }
};

int main()
{
    return 0;
}