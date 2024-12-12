#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto i : gifts)
        {
            pq.push(i);
            ans += i;
        }
        while (k-- && !pq.empty())
        {
            int val = pq.top();
            pq.pop();
            int rem = sqrt(val);
            ans -= (val - rem);
            if (rem)
                pq.push(rem);
        }
        return ans;
    }
};
int main()
{
    return 0;
}