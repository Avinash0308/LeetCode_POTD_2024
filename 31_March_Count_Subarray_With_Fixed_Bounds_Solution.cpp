#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int last_min = -1, last_max = -1;
        int start = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (minK > nums[i] || maxK < nums[i])
                start = last_min = last_max = i;
            else
            {
                if (nums[i] == minK)
                    last_min = i;
                if (nums[i] == maxK)
                    last_max = i;
                ans += min(last_min, last_max) - start;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}