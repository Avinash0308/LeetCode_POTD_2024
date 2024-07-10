#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int cur = 0;
        for (auto log : logs)
        {
            if (log == "../")
                cur = max(0, cur - 1);
            else if (log != "./")
                cur++;
        }
        return cur;
    }
};

int main()
{
    return 0;
}