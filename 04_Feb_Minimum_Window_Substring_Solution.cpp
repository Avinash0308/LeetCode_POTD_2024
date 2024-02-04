#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> text(256);
        for (auto i : t)
        {
            text[(int)i]++;
        }
        int ans = INT_MAX, ind1, ind2;
        int start = 0, end = -1;
        vector<int> cur(256);
        for (int k = 0; k < s.size(); k++)
        {
            char i = s[k];
            cur[(int)i]++;
            int pos = 1;
            for (int j = 0; j < 256; j++)
            {
                if (cur[j] < text[j])
                {
                    pos = 0;
                    break;
                }
            }
            if (pos)
            {
                while (start <= k && cur[(int)s[start]] - 1 >= text[(int)s[start]])
                {
                    cur[(int)s[start]]--;
                    start++;
                }
                if (ans > k - start + 1)
                {
                    ind1 = start;
                    ind2 = k;
                    ans = k - start + 1;
                }
            }
        }
        if (ans == INT_MAX)
            return "";
        string res = s.substr(ind1, ind2 - ind1 + 1);
        return res;
    }
};