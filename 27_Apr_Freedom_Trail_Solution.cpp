#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[ring[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        for (int i = 0; i < key.size(); i++)
        {
            int miny = INT_MAX, ind = -1;
            unordered_map<int, int> m;
            int qs = q.size();
            for (int x = 0; x < qs; x++)
            {
                int start = q.front().first;
                int sum = q.front().second;
                q.pop();
                for (auto j : mp[key[i]])
                {
                    int a = abs(j - start);
                    a = min(a, n - a);
                    if (m.count(j) == 0 || m[j] > sum + a + 1)
                    {
                        m[j] = sum + a + 1;
                    }
                }
            }
            for (auto j : m)
            {
                q.push({j.first, j.second});
            }
        }
        int ans = INT_MAX;
        while (!q.empty())
        {
            ans = min(ans, q.front().second);
            q.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}