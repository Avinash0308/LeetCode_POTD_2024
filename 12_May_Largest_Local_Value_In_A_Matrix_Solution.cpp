#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> v(n - 2, vector<int>(n - 2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                for (int x = 0; x >= -2; x--)
                {
                    for (int y = 0; y >= -2; y--)
                    {
                        if (x + i >= 0 && x + i < n - 2 && y + j >= 0 && y + j < n - 2)
                        {
                            v[x + i][y + j] = max(v[x + i][y + j], grid[i][j]);
                        }
                    }
                }
            }
        }
        return v;
    }
};

int main()
{
    return 0;
}