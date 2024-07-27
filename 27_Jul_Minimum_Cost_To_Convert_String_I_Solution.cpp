#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<long long>> v(26, vector<long long>(26, INT_MAX));
        unordered_map<char, vector<pair<char, long long>>> mp;
        for (int i = 0; i < original.size(); i++)
        {
            mp[original[i]].push_back({changed[i], cost[i]});
        }
        for (auto i : mp)
        {
            queue<pair<char, long long>> q;
            for (auto j : i.second)
            {
                q.push(j);
            }
            while (!q.empty())
            {
                char val = q.front().first;
                long long dis = q.front().second;
                q.pop();
                if (v[i.first - 'a'][val - 'a'] > dis)
                {
                    v[i.first - 'a'][val - 'a'] = dis;
                    for (auto j : mp[val])
                    {
                        q.push({j.first, j.second + dis});
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] == target[i])
                continue;
            if (v[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                return -1;
            ans += v[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};

int main()
{
    return 0;
}