#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        unordered_map<int, vector<pair<double, int>>> e;
        int ii = 0;
        for (auto i : edges)
        {
            e[i[0]].push_back({succProb[ii], i[1]});
            e[i[1]].push_back({succProb[ii], i[0]});
            ii++;
        }
        vector<int> vis(n);
        priority_queue<pair<double, int>> q;
        q.push({1.0, start_node});
        while (!q.empty())
        {
            double val = q.top().first;
            int ind = q.top().second;
            q.pop();
            if (vis[ind])
                continue;
            vis[ind] = 1;
            if (ind == end_node)
                return val;
            for (auto i : e[ind])
            {
                q.push({val * i.first, i.second});
            }
        }
        return 0.0;
    }
};

int main()
{
    return 0;
}