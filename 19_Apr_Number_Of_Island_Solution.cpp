#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            continue;
                        if (grid[x][y] == '1')
                        {
                            grid[x][y] = '0';
                            q.push({x - 1, y});
                            q.push({x + 1, y});
                            q.push({x, y - 1});
                            q.push({x, y + 1});
                        }
                    }
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