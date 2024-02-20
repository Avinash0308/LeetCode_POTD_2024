#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        long long int val = (n * (n + 1)) / 2;
        for (auto v : nums)
            val -= v;
        return val;
    }
};