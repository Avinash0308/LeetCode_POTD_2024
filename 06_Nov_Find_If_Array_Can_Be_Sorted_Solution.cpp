#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int prev = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < 9; j++)
            {
                if ((1 << j) & (nums[i]))
                    cur++;
            }
            int sm = nums[i], bg = nums[i];
            while (i + 1 < n)
            {
                int val = 0;
                for (int j = 0; j < 9; j++)
                {
                    if ((1 << j) & nums[i + 1])
                        val++;
                }
                if (val == cur)
                {
                    i++;
                    sm = min(sm, nums[i]);
                    bg = max(bg, nums[i]);
                }
                else
                {
                    break;
                }
            }
            if (sm < prev)
                return false;
            prev = bg;
        }
        return true;
    }
};

int main()
{
    return 0;
}