#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_map<string, int> mp;
        for (auto str : deadends)
        {
            mp[str] = 1;
        }
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while (!q.empty())
        {
            string cur = q.front().first;
            int mov = q.front().second;
            q.pop();
            if (cur == target)
                return mov;
            if (mp.count(cur) != 0)
                continue;
            mp[cur] = 1;
            for (int i = 0; i < 4; i++)
            {
                char c = cur[i];
                cur[i] = char(((c - '0' + 1) % 10) + 48);
                q.push({cur, mov + 1});
                cur[i] = char(((c - '0' + 9) % 10) + 48);
                q.push({cur, mov + 1});
                cur[i] = c;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}