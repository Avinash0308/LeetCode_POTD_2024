#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &s, int &n, vector<int> &ans)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (i == 0 && s.empty())
                continue;
            s += to_string(i);
            if (stoi(s) > n)
            {
                s.pop_back();
                return;
            }
            ans.push_back(stoi(s));
            solve(s, n, ans);
            s.pop_back();
        }
        return;
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        string s = "";
        solve(s, n, ans);
        return ans;
    }
};

int main()
{
    return 0;
}