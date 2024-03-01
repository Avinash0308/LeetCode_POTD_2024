#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int cnt = 0;
        for (auto str : s)
            if (str == '1')
                cnt++;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt > 1)
            {
                s[i] = '1';
                cnt--;
            }
            else
                s[i] = '0';
        }
        s[n - 1] = '1';
        return s;
    }
};
int main()
{

    return 0;
}