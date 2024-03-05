#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j])
        {
            while (i < j && s[i] == s[i + 1])
                i++;
            while (j > i && s[j] == s[j - 1])
                j--;
            i++;
            j--;
        }
        if (i <= j)
            return j - i + 1;
        else
            return 0;
    }
};