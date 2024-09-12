#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        vector<int> all(26);
        for (auto i : allowed)
        {
            all[i - 'a'] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < words.size(); i++)
        {
            bool pos = true;
            for (auto j : words[i])
            {
                if (all[j - 'a'] == 0)
                {
                    pos = false;
                    break;
                }
            }
            cnt += pos;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}