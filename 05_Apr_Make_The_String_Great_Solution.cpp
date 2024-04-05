#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string str;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (str.empty())
            {
                str.push_back(s[i]);
            }
            else
            {
                if (abs(str.back() - s[i]) == 32)
                    str.pop_back();
                else
                    str.push_back(s[i]);
            }
        }
        return str;
    }
};

int main()
{
    return 0;
}