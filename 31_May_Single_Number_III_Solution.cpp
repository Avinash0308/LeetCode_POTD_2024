#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i <= 31; i++)
        {
            int val = 1 << i;
            int first = 0, second = 0, one = 0;
            for (auto x : nums)
            {
                if (x & val)
                {
                    first ^= x;
                    one++;
                }
                else
                {
                    second ^= x;
                }
            }
            if (one % 2)
                return {first, second};
        }
        return {-1, -1};
    }
};

int main()
{
    return 0;
}