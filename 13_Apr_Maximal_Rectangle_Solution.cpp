#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int val = (i == 0) ? 0 : v[i - 1][j];
                    v[i][j] = val + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int miny = INT_MAX;
                for (int k = j; k < m; k++)
                {
                    miny = min(miny, v[i][k]);
                    ans = max(ans, miny * (k - j + 1));
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