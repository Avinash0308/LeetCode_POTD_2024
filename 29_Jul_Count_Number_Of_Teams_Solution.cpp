#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        ordered_set a, b;
        for (int i = 1; i < n; i++)
            b.insert(rating[i]);
        a.insert(rating[0]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            a.insert(rating[i]);
            int l1 = a.order_of_key(rating[i]);
            int l2 = i - l1;
            int r1 = b.order_of_key(rating[i]);
            int r2 = n - i - 1 - r1;
            ans += l1 * r2 + l2 * r1;
            b.erase(rating[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}