#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int check(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return 1;
        return 0;
    }
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int low = 0, high = n - 1;
        int a = 0, b = 0;
        while (low < high)
        {
            char c = s[low], d = s[high];
            a += check(c);
            b += check(d);
            low++, high--;
        }
        return a == b;
    }
};