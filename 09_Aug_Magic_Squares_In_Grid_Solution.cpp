#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (int i = 2; i < n; i++)
        {
            for (int j = 2; j < m; j++)
            {
                int val = grid[i][j] + grid[i - 1][j] + grid[i - 2][j];
                if ((val == (grid[i][j - 1] + grid[i - 1][j - 1] + grid[i - 2][j - 1])) && (val == (grid[i][j - 2] + grid[i - 1][j - 2] + grid[i - 2][j - 2])) && (val == (grid[i][j] + grid[i][j - 1] + grid[i][j - 2])) && (val == (grid[i - 1][j] + grid[i - 1][j - 1] + grid[i - 1][j - 2])) && (val == (grid[i - 2][j] + grid[i - 2][j - 1] + grid[i - 2][j - 2])) && (val == (grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2])) && (val == (grid[i][j - 2] + grid[i - 1][j - 1] + grid[i - 2][j])))
                {
                    unordered_map<int, int> mp;
                    for (int x = i; x >= i - 2; x--)
                    {
                        for (int y = j; y >= j - 2; y--)
                        {
                            mp[grid[x][y]]++;
                        }
                    }
                    int count = 0;
                    for (int x = 1; x <= 9; x++)
                    {
                        if (mp.count(x) != 0)
                            count++;
                    }
                    if (count == 9)
                        ans++;
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