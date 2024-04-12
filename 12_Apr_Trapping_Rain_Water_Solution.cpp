#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int max1 = 0, max2 = 0;
        int low = 0, high = n - 1;
        int ans = 0;
        while (low <= high)
        {
            if (height[low] <= height[high])
            {
                max1 = max(max1, height[low]);
                ans += max1 - height[low];
                low++;
            }
            else
            {
                max2 = max(max2, height[high]);
                ans += max2 - height[high];
                high--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}