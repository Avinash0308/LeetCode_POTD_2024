#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        long long int ans = INT_MAX;
        long long int n = nums.size(), cur = 0;
        vector<long long int> prev;
        vector<long long int> ind;
        prev.push_back(0);
        ind.push_back(-1);
        for (long long int i = 0; i < n; i++)
        {
            cur += nums[i];
            long long int val = cur - k;
            long long int ind1 = (upper_bound(prev.begin(), prev.end(), val) - prev.begin()) - 1;
            if (ind1 >= 0)
                ans = min(ans, i - ind[ind1]);
            while (!prev.empty() && prev.back() >= cur)
                prev.pop_back(), ind.pop_back();
            prev.push_back(cur);
            ind.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    return 0;
}