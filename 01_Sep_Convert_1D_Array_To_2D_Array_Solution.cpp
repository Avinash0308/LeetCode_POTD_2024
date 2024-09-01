#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> ans;
        if (original.size() != m * n)
            return {};
        for (int i = 0; i < m * n; i += n)
        {
            vector<int> cur;
            for (int j = 0; j < n; j++)
            {
                cur.push_back(original[i + j]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};

int main()
{
    return 0;
}