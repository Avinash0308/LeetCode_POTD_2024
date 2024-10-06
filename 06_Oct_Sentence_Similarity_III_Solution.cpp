#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSentencesSimilar(string a, string b)
    {
        if (a == b)
            return true;
        int n = a.size(), m = b.size();
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            cnt1++;
            while (i < n && a[i] != ' ')
                i++;
        }
        for (int i = 0; i < m; i++)
        {
            cnt2++;
            while (i < m && b[i] != ' ')
                i++;
        }
        int x = 0, i = 0;
        while (i < n && i < m && a[i] == b[i])
        {
            i++;
            if ((i == n || a[i] == ' ') && (i == m || b[i] == ' '))
                x++;
        }
        int y = 0, j = n - 1, k = m - 1;
        while (j >= 0 && k >= 0 && a[j] == b[k])
        {
            j--, k--;
            if ((j == -1 || a[j] == ' ') && (k == -1 || b[k] == ' '))
                y++;
        }
        if (x + y >= cnt1 || x + y >= cnt2)
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}