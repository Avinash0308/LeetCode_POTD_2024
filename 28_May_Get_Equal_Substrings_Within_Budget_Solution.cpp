#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int ans = 0;
        int start = 0;
        int i = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            maxCost -= abs(s[i] - t[i]);
            while (maxCost < 0)
            {
                maxCost += abs(s[start] - t[start]);
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}