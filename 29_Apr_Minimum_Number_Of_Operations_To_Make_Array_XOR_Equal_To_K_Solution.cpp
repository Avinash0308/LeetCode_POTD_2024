#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int xorr = 0;
        for (auto num : nums)
            xorr ^= num;
        int val = 1;
        int op = 0;
        for (int i = 0; i < 31; i++)
        {
            if ((val & k) != (val & xorr))
                op++;
            val <<= 1;
        }
        return op;
    }
};

int main()
{
    return 0;
}