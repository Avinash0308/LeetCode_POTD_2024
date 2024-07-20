#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m));
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            i += (rowSum[i] == 0);
            j += (colSum[j] == 0);
        }
        return ans;
    }
};

int main()
{
    return 0;
}