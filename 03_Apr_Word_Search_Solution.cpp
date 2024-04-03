#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int ind, int i, int j, vector<vector<int>> &v, string &word, vector<vector<char>> &board, int n, int m)
    {
        if (ind == word.size())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || v[i][j] || board[i][j] != word[ind])
            return false;
        v[i][j] = 1;
        bool pos = false;
        if (solve(ind + 1, i, j - 1, v, word, board, n, m) || solve(ind + 1, i, j + 1, v, word, board, n, m) || solve(ind + 1, i - 1, j, v, word, board, n, m) || solve(ind + 1, i + 1, j, v, word, board, n, m))
            pos = true;
        v[i][j] = 0;
        return pos;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (solve(0, i, j, v, word, board, n, m))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}