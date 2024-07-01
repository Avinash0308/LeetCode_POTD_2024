#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int cur = 0;
        for (auto i : arr)
        {
            if (i % 2)
                cur++;
            else
                cur = 0;
            if (cur == 3)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}