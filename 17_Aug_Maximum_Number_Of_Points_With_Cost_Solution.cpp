#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> left(vector<long long> &a)
    {
        long long n = a.size();
        vector<long long> ans(n);
        for (long long i = 0; i < n; i++)
        {
            ans[i] = a[i];
            if (i > 0)
                ans[i] = max(ans[i], ans[i - 1] - 1);
        }
        return ans;
    }
    vector<long long> right(vector<long long> &a)
    {
        long long n = a.size();
        vector<long long> ans(n);
        for (long long i = n - 1; i >= 0; i--)
        {
            ans[i] = a[i];
            if (i < n - 1)
                ans[i] = max(ans[i], ans[i + 1] - 1);
        }
        return ans;
    }
    long long maxPoints(vector<vector<int>> &points)
    {
        int n = points.size(), m = points[0].size();
        vector<long long> last(m);
        for (int i = 0; i < m; i++)
        {
            last[i] = points[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            vector<long long> l = left(last);
            vector<long long> r = right(last);
            for (int j = 0; j < m; j++)
            {
                last[j] = points[i][j] + max(l[j], r[j]);
            }
        }
        long long ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, last[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}