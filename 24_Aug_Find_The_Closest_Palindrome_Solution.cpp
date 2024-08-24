#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string nearestPalindromic(string s)
    {
        long long int ori = stoll(s);
        if (ori <= 10)
            return to_string(ori - 1);
        if (s == "11")
            return "9";
        int n = s.size();
        string half = s.substr(0, (n + 1) / 2);
        vector<long long int> v(5);
        long long int num = stoll(half);
        v[0] = solve(num - 1, n % 2);
        v[1] = solve(num, n % 2);
        v[2] = solve(num + 1, n % 2);
        v[3] = pow(10, n - 1) - 1;
        v[4] = pow(10, n) + 1;
        long long int miny = LLONG_MAX, ans = 0;
        for (auto i : v)
        {
            if (i == ori)
                continue;
            long long int diff = abs(i - ori);
            if (diff < miny)
            {
                miny = diff;
                ans = i;
            }
            else if (diff == miny && ans > i)
            {
                ans = i;
            }
        }
        return to_string(ans);
    }
    long long int solve(long long int num, int parity)
    {
        long long int cur = num;
        if (parity)
            num /= 10;
        while (num)
        {
            cur = cur * 10 + num % 10;
            num /= 10;
        }
        return cur;
    }
};

int main()
{
    return 0;
}