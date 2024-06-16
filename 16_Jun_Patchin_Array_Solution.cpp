#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int x)
    {
        long long int cur = 0;
        long long int total = 0;
        long long int i = 0;
        long long int n = nums.size();
        while (i < n && cur < x)
        {
            while (i < n && nums[i] <= cur + 1 && cur < x)
            {
                cur += nums[i];
                i++;
            }
            if (cur >= x)
                return total;
            cur += cur + 1;
            total++;
        }
        while (cur < x)
        {
            cur += cur + 1;
            total++;
        }
        return total;
    }
};

int main()
{
    return 0;
}