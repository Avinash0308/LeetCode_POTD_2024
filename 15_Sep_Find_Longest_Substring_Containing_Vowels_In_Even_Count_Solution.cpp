#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<string, int> mp;
        mp["00000"] = -1;
        int ans = 0;
        int n = s.size();
        string x = "00000";
        for (int i = 0; i < n; i++)
        {
            int val = -1;
            if (s[i] == 'a')
                val = 1;
            else if (s[i] == 'e')
                val = 2;
            else if (s[i] == 'i')
                val = 3;
            else if (s[i] == 'o')
                val = 4;
            else if (s[i] == 'u')
                val = 5;
            if (val != -1 && x[val - 1] == '1')
            {
                x[val - 1] = '0';
            }
            else if (val != -1 && x[val - 1] == '0')
            {
                x[val - 1] = '1';
            }
            if (mp.count(x) != 0)
            {
                ans = max(ans, i - mp[x]);
            }
            else
            {
                mp[x] = i;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}