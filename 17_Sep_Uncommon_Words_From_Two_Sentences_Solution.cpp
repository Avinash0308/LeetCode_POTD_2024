#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            string cur;
            while (i < n && s1[i] != ' ')
            {
                cur += s1[i];
                i++;
            }
            mp[cur]++;
        }
        n = s2.size();
        for (int i = 0; i < n; i++)
        {
            string cur;
            while (i < n && s2[i] != ' ')
            {
                cur += s2[i];
                i++;
            }
            mp[cur]++;
        }
        vector<string> ans;
        for (auto i : mp)
        {
            if (i.second == 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};

int main()
{
    return 0;
}