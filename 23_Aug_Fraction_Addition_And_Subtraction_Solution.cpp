#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionAddition(string e)
    {
        int a = 0, b = 1;
        int n = e.size();
        for (int i = 0; i < n; i++)
        {
            int neg = 0;
            int num = 0, den = 0;
            if (e[i] == '-')
            {
                neg = 1;
                i++;
            }
            else if (e[i] == '+')
                i++;
            while (e[i] != '/')
            {
                num = num * 10 + e[i] - '0';
                i++;
            }
            while (i + 1 < n && e[i + 1] != '-' && e[i + 1] != '+')
            {
                den = den * 10 + e[i + 1] - '0';
                i++;
            }
            int lcm = (b * den) / __gcd(b, den);
            a *= (lcm / b);
            num *= (lcm / den);
            b = lcm;
            if (neg)
                a -= num;
            else
                a += num;
        }
        if (a == 0)
            return "0/1";
        string ans;
        int neg = 0;
        if (a < 0)
        {
            a = abs(a);
            neg = 1;
        }
        int div = __gcd(a, b);
        a /= div;
        b /= div;
        ans = ((neg) ? "-" : "") + to_string(a) + "/" + to_string(b);
        return ans;
    }
};

int main()
{
    return 0;
}