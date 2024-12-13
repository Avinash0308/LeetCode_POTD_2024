#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }
        while (!pq.empty())
        {
            vector<int> cur = pq.top();
            pq.pop();
            if (nums[cur[1]] == -1)
                continue;
            ans += nums[cur[1]];
            nums[cur[1]] = -1;
            if (cur[1])
                nums[cur[1] - 1] = -1;
            if (cur[1] < n - 1)
                nums[cur[1] + 1] = -1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}