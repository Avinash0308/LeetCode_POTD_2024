#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> mp;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            string cur = "+";
            char prev = '+';
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == matrix[i][j - 1])
                    cur += prev;
                else
                {
                    if (prev == '+')
                        prev = '-';
                    else
                        prev = '+';
                    cur += prev;
                }
            }
            mp[cur]++;
        }
        int ans = 0;
        for (auto i : mp)
            ans = max(ans, i.second);
        return ans;
    }
};

int main()
{
    return 0;
}