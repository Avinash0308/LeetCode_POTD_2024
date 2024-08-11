#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visit)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || visit[i][j] || !grid[i][j])
            return;
        visit[i][j] = 1;
        for (int ind = 0; ind < 4; ind++)
        {
            dfs(grid, i + dir[ind][0], j + dir[ind][1], visit);
        }
    }
    bool count(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visit[i][j] == 0)
                {
                    if (count)
                        return true;
                    count++;
                    dfs(grid, i, j, visit);
                }
            }
        }
        return count == 0;
    }
    int minDays(vector<vector<int>> &grid)
    {
        if (count(grid))
            return 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    if (count(grid))
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};

int main()
{
    return 0;
}