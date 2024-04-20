#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &lead)
    {
        vector<vector<int>> ans;
        int cur = 1;
        int n = lead.size(), m = lead[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (lead[i][j] == 0)
                    continue;
                if (i > 0 && lead[i - 1][j] != 0)
                    lead[i][j] = lead[i - 1][j];
                else if (j > 0 && lead[i][j - 1] != 0)
                    lead[i][j] = lead[i][j - 1];
                else
                {
                    lead[i][j] = cur;
                    cur++;
                    ans.push_back({i, j});
                }
                if ((i == n - 1 || lead[i + 1][j] == 0) && (j == m - 1 || lead[i][j + 1] == 0))
                {
                    ans[lead[i][j] - 1].push_back(i);
                    ans[lead[i][j] - 1].push_back(j);
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