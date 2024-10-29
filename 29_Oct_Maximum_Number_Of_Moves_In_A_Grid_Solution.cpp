#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > 0 && grid[j - 1][i + 1] > grid[j][i])
                    ans[j][i] = 1 + ans[j - 1][i + 1];
                if (grid[j][i + 1] > grid[j][i])
                    ans[j][i] = max(ans[j][i], 1 + ans[j][i + 1]);
                if (j < n - 1 && grid[j + 1][i + 1] > grid[j][i])
                    ans[j][i] = max(ans[j][i], 1 + ans[j + 1][i + 1]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, ans[i][0]);
        }
        return res;
    }
};

int main()
{
    return 0;
}