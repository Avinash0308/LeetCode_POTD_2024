#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j])
                    matrix[i][j] += matrix[i - 1][j];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int miny = n + 1;
                for (int k = j; k >= 0; k--)
                {
                    miny = min(miny, matrix[i][k]);
                    if (miny < j - k + 1)
                        k = 0;
                    else
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