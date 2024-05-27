#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int len = n - i;
            if (len <= nums[i] && (i == 0 || nums[i - 1] < len))
                return len;
        }
        return -1;
    }
};

int main()
{
    return 0;
}