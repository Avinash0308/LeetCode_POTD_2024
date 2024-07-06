#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if (n == 1)
            return 1;
        int pass = time / (n - 1);
        time -= pass * (n - 1);
        if (pass % 2)
            return n - time;
        else
            return 1 + time;
    }
};

int main()
{
    return 0;
}