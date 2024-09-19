#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int i, int j, string &e, vector<vector<vector<int>>> &v)
    {
        if (!v[i][j].empty())
            return v[i][j];
        vector<int> res;
        for (int x = i; x <= j; x++)
        {
            char c = e[x];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> a = solve(i, x - 1, e, v);
                vector<int> b = solve(x + 1, j, e, v);
                for (auto d : a)
                {
                    for (auto e : b)
                    {
                        if (c == '+')
                            res.push_back(d + e);
                        else if (c == '*')
                            res.push_back(d * e);
                        else
                            res.push_back(d - e);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(stoi(e.substr(i, j - i + 1)));
        return v[i][j] = res;
    }
    vector<int> diffWaysToCompute(string e)
    {
        int n = e.size();
        vector<vector<vector<int>>> v(n, vector<vector<int>>(n));
        return solve(0, n - 1, e, v);
    }
};

int main()
{
    return 0;
}