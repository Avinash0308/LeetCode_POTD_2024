#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> cnt(26, INT_MAX);
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> v(26, 0);
            for (auto j : words[i])
            {
                v[j - 'a']++;
            }
            for (int x = 0; x < 26; x++)
            {
                cnt[x] = min(cnt[x], v[x]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            string s;
            s.push_back(char(i + 97));
            while (cnt[i]--)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}