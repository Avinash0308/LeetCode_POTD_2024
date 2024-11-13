#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        int n = nums.size();
        ordered_set s;
        for (int i = 0; i < n; i++)
        {
            int high = upper - nums[i] + 1;
            int low = lower - nums[i];
            ans += s.order_of_key(high) - s.order_of_key(low);
            s.insert(nums[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}