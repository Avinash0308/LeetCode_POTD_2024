#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int val = 0, len = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (val > nums[i])
                continue;
            int siz = 1;
            while (i < n - 1 && nums[i] == nums[i + 1])
                i++, siz++;
            if (val == nums[i])
                len = max(len, siz);
            else
            {
                val = nums[i];
                len = siz;
            }
        }
        return len;
    }
};

int main()
{
    return 0;
}