#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, unordered_map<int, int>> row, col;
        for (auto i : stones)
        {
            row[i[0]][i[1]] = 1;
            col[i[1]][i[0]] = 1;
        }
        int ans = stones.size();
        for (auto i : stones)
        {
            if (row.count(i[0]) == 0 || row[i[0]].count(i[1]) == 0)
                continue;
            ans--;
            queue<pair<int, int>> q;
            q.push({i[0], i[1]});
            while (!q.empty())
            {
                int r = q.front().first, c = q.front().second;
                row[r].erase(c);
                col[c].erase(r);
                q.pop();
                for (auto x : row[r])
                {
                    q.push({r, x.first});
                }
                for (auto y : col[c])
                {
                    q.push({y.first, c});
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