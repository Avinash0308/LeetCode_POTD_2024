#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string a, string b)
    {
        int n = a.size(), m = b.size();
        if (m > n)
            return false;
        int i = 0, j = 0;
        while (j < m && i < n)
        {
            if (a[i] == b[j] || b[j] == char((a[i] - 'a' + 1) % 26 + 97))
                j++;
            i++;
        }
        return j == m;
    }
};

int main()
{
    return 0;
}