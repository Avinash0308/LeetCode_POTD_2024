#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long long int> s;
        s.insert(1);
        n--;
        while (n--)
        {
            long long int val = *(s.begin());
            s.erase(s.begin());
            s.insert(val * 2);
            s.insert(val * 3);
            s.insert(val * 5);
        }
        return *(s.begin());
    }
};

int main()
{
    return 0;
}