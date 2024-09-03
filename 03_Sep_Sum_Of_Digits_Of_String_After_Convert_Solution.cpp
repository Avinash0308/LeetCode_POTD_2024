#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string num = "";
        for (int i = 0; i < s.size(); i++)
        {
            int val = 1 + s[i] - 'a';
            num += to_string(val);
        }
        for (int i = 0; i < k; i++)
        {
            int val = 0;
            for (auto j : num)
            {
                val += j - '0';
            }
            num = to_string(val);
        }
        return stoi(num);
    }
};

int main()
{
    return 0;
}