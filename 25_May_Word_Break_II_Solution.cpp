#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int ind, string word, string &cur, vector<string> &ans, string &s, unordered_map<string, int> &mp)
    {
        if (ind == s.size())
        {
            if (word.empty())
            {
                ans.push_back(cur);
            }
            return;
        }
        word.push_back(s[ind]);
        solve(ind + 1, word, cur, ans, s, mp);
        if (mp.count(word) != 0)
        {
            int len = cur.size();
            if (len)
            {
                cur += " ";
            }
            cur += word;
            solve(ind + 1, "", cur, ans, s, mp);
            cur.erase(len, word.size() + 1);
        }
        word.pop_back();
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> mp;
        for (auto word : wordDict)
        {
            mp[word]++;
        }
        vector<string> ans;
        string cur;
        string word;
        solve(0, word, cur, ans, s, mp);
        return ans;
    }
};

int main()
{
    return 0;
}