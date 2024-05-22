#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool palin(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    void solve(int ind, string str, vector<string> &cur, vector<vector<string>> &ans, string &s)
    {
        int n = s.size();
        if (ind == n)
        {
            if (!str.empty())
                return;
            ans.push_back(cur);
            return;
        }
        str.push_back(s[ind]);
        solve(ind + 1, str, cur, ans, s);
        if (palin(str))
        {
            cur.push_back(str);
            solve(ind + 1, "", cur, ans, s);
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> cur;
        solve(0, "", cur, ans, s);
        return ans;
    }
};

int main()
{
    return 0;
}