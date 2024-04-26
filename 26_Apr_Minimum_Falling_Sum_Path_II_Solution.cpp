#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x = INT_MAX, y = INT_MAX;
                if (j > 0)
                    x = a[j - 1];
                if (j < n - 1)
                    y = b[j + 1];
                grid[i][j] += min(x, y);
            }
            a[0] = grid[i][0];
            for (int j = 1; j < n; j++)
            {
                a[j] = min(a[j - 1], grid[i][j]);
            }
            b[n - 1] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--)
            {
                b[j] = min(b[j + 1], grid[i][j]);
            }
        }
        return a[n - 1];
    }
};

int main()
{
    return 0;
}