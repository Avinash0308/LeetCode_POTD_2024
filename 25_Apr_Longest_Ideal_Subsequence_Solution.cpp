#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        vector<int> v(n);
        vector<int> pos(26, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            int low = max(int(s[i]) - k, 97) - 97;
            int high = min(int(s[i]) + k, 122) - 97;
            for (int j = low; j <= high; j++)
            {
                if (pos[j] != -1)
                {
                    v[i] = max(v[i], v[pos[j]]);
                }
            }
            pos[s[i] - 'a'] = i;
            v[i]++;
            ans = max(ans, v[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}