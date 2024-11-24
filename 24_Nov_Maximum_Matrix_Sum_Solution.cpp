#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long cnt = 0, maxy = INT_MAX, ans = 0;
        for (auto i : matrix)
        {
            for (auto j : i)
            {
                ans += abs(j);
                if (j < 0)
                    cnt++;
                maxy = min(maxy, (long long)(abs(j)));
            }
        }
        if (cnt % 2)
        {
            return ans - 2 * maxy;
        }
        else
            return ans;
    }
};

int main()
{
    return 0;
}