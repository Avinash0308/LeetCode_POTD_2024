#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            int maxy = 0;
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] > nums[j])
                    maxy = max(maxy, a[j]);
            a[i] = maxy + 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int maxy = 0;
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    maxy = max(maxy, b[j]);
            b[i] = maxy + 1;
        }
        int ans = n;
        for (int i = 1; i < n - 1; i++)
        {
            int x = 0, y = 0;
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] > nums[j])
                    x = max(x, a[j]);
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    y = max(y, b[j]);
            if (x && y)
                ans = min(ans, n - (x + y + 1));
        }
        return ans;
    }
};

int main()
{
    return 0;
}