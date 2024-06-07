#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_map<string, int> mp;
        for (auto i : dictionary)
        {
            mp[i]++;
        }
        string ans;
        int n = sentence.size();
        for (int i = 0; i < n; i++)
        {
            string cur;
            bool found = 0;
            while (i < n && sentence[i] != ' ')
            {
                cur.push_back(sentence[i]);
                if (!found && mp.count(cur) != 0)
                {
                    ans += cur;
                    ans += " ";
                    found = 1;
                }
                i++;
            }
            if (!found)
            {
                ans += cur;
                ans += " ";
            }
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
    return 0;
}