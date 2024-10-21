#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans;
    unordered_map<string, int> mp;

public:
    void solve(int ind, string &cur, string &s, int cnt)
    {
        if (ind == s.size())
        {
            if (cur.empty())
                ans = max(ans, cnt);
            return;
        }
        cur += s[ind];
        solve(ind + 1, cur, s, cnt);
        if (mp[cur] == 0)
        {
            string scur;
            mp[cur] = 1;
            solve(ind + 1, scur, s, cnt + 1);
            mp[cur] = 0;
        }
        cur.pop_back();
    }
    int maxUniqueSplit(string s)
    {
        string cur;
        ans = 0;
        solve(0, cur, s, 0);
        return ans;
    }
};

int main()
{
    return 0;
}