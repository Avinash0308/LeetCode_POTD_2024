#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.empty() || nums[s.top()] > nums[i])
            {
                s.push(i);
            }
        }
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] <= nums[i])
            {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}