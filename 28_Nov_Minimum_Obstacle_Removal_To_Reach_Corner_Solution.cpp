#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        v[0][0] = grid[0][0];
        q.push({v[0][0], 0, 0});
        while (!q.empty())
        {
            vector<int> cur = q.top();
            q.pop();
            if (cur[1] == n - 1 && cur[2] == m - 1)
                return v[cur[1]][cur[2]];
            for (auto i : dir)
            {
                if (cur[1] + i[0] >= 0 && cur[1] + i[0] < n && cur[2] + i[1] >= 0 && cur[2] + i[1] < m && cur[0] + grid[cur[1] + i[0]][cur[2] + i[1]] < v[cur[1] + i[0]][cur[2] + i[1]])
                {
                    v[cur[1] + i[0]][cur[2] + i[1]] = cur[0] + grid[cur[1] + i[0]][cur[2] + i[1]];
                    q.push({v[cur[1] + i[0]][cur[2] + i[1]], cur[1] + i[0], cur[2] + i[1]});
                }
            }
        }
        return v[n - 1][m - 1];
    }
};

int main()
{
    return 0;
}