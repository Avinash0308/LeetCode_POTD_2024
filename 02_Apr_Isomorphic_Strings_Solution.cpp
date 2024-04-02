#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> a(256, -1), b(256, -1);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int x = (int)s[i];
            int y = (int)t[i];
            if ((a[x] == y || a[x] == -1) && (b[y] == x || b[y] == -1))
            {
                a[x] = y;
                b[y] = x;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}