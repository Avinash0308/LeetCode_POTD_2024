#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> par(n, -1);
        for (auto i : edges)
        {
            par[i[1]] = i[0];
        }
        int ind = -1, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (par[i] == -1)
            {
                ind = i;
                cnt++;
            }
        }
        if (cnt == 1)
            return ind;
        else
            return -1;
    }
};

int main()
{
    return 0;
}