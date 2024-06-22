#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int start = 0, odd = 0, ans = 0, last = -1;
        for (auto i : nums)
        {
            if (i % 2)
                odd++;
            while (odd > k)
            {
                if (nums[start] % 2)
                    odd--;
                start++;
            }
            last = start;
            while (last < nums.size() && nums[last] % 2 == 0)
                last++;
            if (odd == k)
                ans += last - start + 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}