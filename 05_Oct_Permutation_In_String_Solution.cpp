#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> a(26), b(26);
        for (auto i : s1)
        {
            a[i - 'a']++;
        }
        int n = s1.size(), m = s2.size();
        for (int i = 0; i < m; i++)
        {
            b[s2[i] - 'a']++;
            if (a == b)
                return true;
            if (i >= n - 1)
                b[s2[i - n + 1] - 'a']--;
        }
        return false;
    }
};

int main()
{
    return 0;
}