#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, unordered_map<int, int>> dp;
        for (auto i : flights)
        {
            dp[i[0]][i[1]] = i[2];
        }
        queue<pair<int, int>> pq;
        pq.push({src, 0});
        vector<int> visit(n, INT_MAX);
        while (!(pq.empty()) && k >= -1)
        {
            int len = pq.size();
            while (len--)
            {
                int ind = pq.front().first;
                int val = pq.front().second;
                pq.pop();
                if (visit[ind] > val)
                {
                    visit[ind] = val;
                    if (ind != dst && dp.count(ind) != 0)
                    {
                        for (auto i : dp[ind])
                        {
                            pq.push({i.first, i.second + val});
                        }
                    }
                }
            }
            k--;
        }
        if (visit[dst] == INT_MAX)
            return -1;
        return visit[dst];
    }
};
int main()
{

    return 0;
}