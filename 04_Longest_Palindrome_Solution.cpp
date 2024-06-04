#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto i : s)
        {
            mp[i]++;
        }
        int odd = 0, total = 0;
        for (auto i : mp)
        {
            total += (i.second / 2) * 2;
            if (i.second % 2)
                odd = 1;
        }
        return total + odd;
    }
};

int main()
{
    return 0;
}