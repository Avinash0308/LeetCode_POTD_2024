#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for (auto e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX || dist[i][j] <= dist[i][k] + dist[k][j])
                        continue;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        int ans = -1;
        int value = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                    cur++;
            }
            if (cur <= value)
            {
                value = cur;
                ans = i;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}