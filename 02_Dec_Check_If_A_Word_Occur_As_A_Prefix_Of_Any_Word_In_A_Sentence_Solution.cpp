#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string b, string a)
    {
        int n = a.size(), m = b.size();
        int cnt = 1;
        for (int i = 0; i < m; i++)
        {
            int j = 0;
            while (j < n && b[i] == a[j])
                j++, i++;
            if (j == n)
                return cnt;
            cnt++;
            while (i < m && b[i] != ' ')
                i++;
        }
        return -1;
    }
};

int main()
{
    return 0;
}