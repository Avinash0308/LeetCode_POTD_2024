#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &v, int m, long long int mid)
    {
        int n = v.size();
        int prev = v[0];
        m--;
        for (int i = 1; i < n; i++)
        {
            if (v[i] - prev >= mid)
            {
                prev = v[i];
                m--;
            }
        }
        return m <= 0;
    }
    int maxDistance(vector<int> &position, int m)
    {
        long long int low = 1, high = 1e9;
        sort(position.begin(), position.end());
        while (low <= high)
        {
            long long int mid = low + ((high - low) / 2);
            if (solve(position, m, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    return 0;
}