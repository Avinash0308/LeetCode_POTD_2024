#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size(), m = box[0].size();
        for (int i = 0; i < n; i++)
        {
            int pos = m - 1;
            for (int j = m - 1; j >= 0; j--)
            {
                if (box[i][j] == '#')
                {
                    box[i][j] = '.';
                    box[i][pos] = '#';
                    pos--;
                }
                else if (box[i][j] == '*')
                    pos = j - 1;
            }
        }
        vector<vector<char>> v(m, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v[j][n - 1 - i] = box[i][j];
            }
        }
        return v;
    }
};

int main()
{
    return 0;
}