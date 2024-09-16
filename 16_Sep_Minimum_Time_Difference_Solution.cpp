#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &t)
    {
        int n = t.size();
        sort(t.begin(), t.end());
        int ans = 1440;
        for (int i = 0; i < n; i++)
        {
            int a = ((t[i][0] - '0') * 10 + (t[i][1] - '0')) * 60 + ((t[i][3] - '0') * 10 + (t[i][4] - '0'));
            int b = ((t[(i + 1) % n][0] - '0') * 10 + (t[(i + 1) % n][1] - '0')) * 60 + ((t[(i + 1) % n][3] - '0') * 10 + (t[(i + 1) % n][4] - '0'));
            ans = min({ans, abs(a - b), abs(1440 + a - b), abs(1440 + b - a)});
        }
        return ans;
    }
};

int main()
{
    return 0;
}