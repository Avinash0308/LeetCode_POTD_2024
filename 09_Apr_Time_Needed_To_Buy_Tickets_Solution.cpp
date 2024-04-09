#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int minPoints(int n, int m, vector<vector<int>> points)
    {
        // Your code goes here
        vector<vector<int>> v(n, vector<int>(m));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                v[i][j] = max(1 - points[i][j], 1);
                if (i == n - 1 && j == m - 1)
                {
                    continue;
                }
                int val1 = INT_MAX, val2 = INT_MAX;
                if (i < n - 1)
                    val1 = v[i + 1][j];
                if (j < m - 1)
                    val2 = v[i][j + 1];
                int cur = v[i][j] + points[i][j];
                int req = min(val1, val2);
                if (cur < req)
                {
                    v[i][j] += req - cur;
                }
            }
        }
        return v[0][0];
    }
};

int main()
{
    return 0;
}