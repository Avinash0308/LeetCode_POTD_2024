#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int start = 0, s = 0, ans = 0, n = grumpy.size(), total = 0;
        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
                total += customers[i];
            else
                s += customers[i];
            if (i - start + 1 > minutes)
            {
                if (grumpy[start])
                    s -= customers[start];
                start++;
            }
            ans = max(ans, s);
        }
        return total + ans;
    }
};

int main()
{
    return 0;
}