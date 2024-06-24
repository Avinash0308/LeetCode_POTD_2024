#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        queue<int> q;
        int ans = 0, n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && q.front() <= i)
            {
                q.pop();
                count--;
            }
            if (count % 2)
                nums[i] = (nums[i] + 1) % 2;
            if (!nums[i])
            {
                if (i + k <= n)
                {
                    ans++;
                    count++;
                    q.push(i + k);
                }
                else
                {
                    return -1;
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