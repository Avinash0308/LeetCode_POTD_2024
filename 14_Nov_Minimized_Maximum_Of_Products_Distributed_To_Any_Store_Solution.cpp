#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool can(int m, vector<int> &q, int n, int mid)
    {
        int i = 0;
        int cnt = 0;
        int cur = 0;
        while (i < m || cur)
        {
            if (cur == 0)
                cur = q[i++];
            cur = max(0, cur - mid);
            cnt++;
        }
        if (cnt <= n)
            return true;
        else
            return false;
    }
    int minimizedMaximum(int n, vector<int> &qu)
    {
        int m = qu.size();
        int low = 1, high = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            high = max(high, qu[i]);
        }
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (can(m, qu, n, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    return 0;
}