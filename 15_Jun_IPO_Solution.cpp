#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int total = w;
        int n = profits.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({profits[i], capital[i]});
        }
        while (k--)
        {
            vector<pair<int, int>> mp;
            while (!pq.empty() && pq.top().second > total)
            {
                mp.push_back({pq.top().first, pq.top().second});
                pq.pop();
            }
            if (pq.empty())
                return total;
            total += pq.top().first;
            pq.pop();
            int xe = mp.size();
            for (int i = xe - 1; i >= 0; i--)
            {
                pq.push({mp[i].first, mp[i].second});
                mp.pop_back();
            }
        }
        return total;
    }
};

int main()
{
    return 0;
}