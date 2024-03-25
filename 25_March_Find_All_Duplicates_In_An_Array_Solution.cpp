#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int mod = n + 1;
        for (int i = 0; i < n; i++)
        {
            nums[(nums[i] % mod) - 1] += mod;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] / mod > 1)
                ans.push_back(i + 1);
            nums[i] %= mod;
        }
        return ans;
    }
};

int main()
{
    return 0;
}