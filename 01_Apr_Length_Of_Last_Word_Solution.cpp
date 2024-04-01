#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        int ans = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == ' ')
            i--;
        while (i >= 0 && s[i] != ' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};

int main()
{
    return 0;
}