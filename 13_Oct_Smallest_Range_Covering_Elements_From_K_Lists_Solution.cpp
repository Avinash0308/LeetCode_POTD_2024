#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxy = INT_MIN;
        int n = nums.size();
        if (n == 1)
            return {nums[0][0], nums[0][0]};
        for (int i = 0; i < n; i++)
        {
            maxy = max(maxy, nums[i][0]);
            pq.push({nums[i][0], 0, i});
        }
        int ans = INT_MAX, start = -1;
        while (1)
        {
            vector<int> x = pq.top();
            pq.pop();
            if (ans > maxy - x[0])
            {
                start = x[0];
                ans = maxy - x[0];
            }
            else if (ans == maxy - x[0] && start > x[0])
                start = x[0];
            if (x[1] == nums[x[2]].size() - 1)
                return {start, ans + start};
            pq.push({nums[x[2]][x[1] + 1], x[1] + 1, x[2]});
            maxy = max(maxy, nums[x[2]][x[1] + 1]);
        }
        return {-1, -1};
    }
};

int main()
{
    return 0;
}