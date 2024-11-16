#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        if (k == 1)
            return nums;
        for (int i = 0; i < n; i++)
        {
            int start = i;
            while (i < n - 1 && nums[i] + 1 == nums[i + 1])
            {
                i++;
                if (i - start + 1 == k)
                {
                    ans[start] = nums[i];
                    start++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}