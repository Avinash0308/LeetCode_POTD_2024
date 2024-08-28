#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int solve(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int n, int m, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] == 0)
            return 1;
        if (grid1[i][j] == 0)
            return 0;
        grid2[i][j] = 0;
        int ans = 1;
        for (auto d : dir)
        {
            if (ans & solve(grid1, grid2, n, m, i + d[0], j + d[1]))
                continue;
            else
                ans = 0;
        }
        return ans;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int ans = 0;
        int n = grid1.size(), m = grid1[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] == 1)
                {
                    ans += solve(grid1, grid2, n, m, i, j);
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}