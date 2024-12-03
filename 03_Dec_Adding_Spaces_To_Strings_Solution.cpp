#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string ans = "";
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (j < spaces.size() && spaces[j] == i)
            {
                j++;
                ans += ' ';
            }
            ans += s[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}