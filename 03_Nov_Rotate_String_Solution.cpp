#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size(), m = goal.size();
        if (n != m)
            return false;
        s += s;
        if (s.find(goal) == string::npos)
            return false;
        else
            return true;
    }
};

int main()
{
    return 0;
}