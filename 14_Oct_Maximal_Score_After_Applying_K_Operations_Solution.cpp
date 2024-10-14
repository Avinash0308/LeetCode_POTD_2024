#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto i : nums)
        {
            pq.push(i);
        }
        for (int i = 0; i < k; i++)
        {
            ans += pq.top();
            int val = pq.top();
            pq.pop();
            pq.push((val + 2) / 3);
        }
        return ans;
    }
};

int main()
{
    return 0;
}