#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int one = 0;
        for (auto i : nums)
            if (i == 1)
                one++;
        if (!one)
            return 0;
        int ans = INT_MAX, cur = 0;
        for (int i = 0; i < one - 1; i++)
        {
            if (nums[i] == 1)
                cur++;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[(i + one - 1) % n] == 1)
                cur++;
            ans = min(ans, one - cur);
            if (nums[i] == 1)
                cur--;
        }
        return ans;
    }
};

int main()
{
    return 0;
}