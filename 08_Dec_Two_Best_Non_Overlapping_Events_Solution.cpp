#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        long long int n = events.size();
        vector<long long int> end, val;
        for (long long int i = 0; i < n; i++)
        {
            swap(events[i][0], events[i][1]);
        }
        sort(events.begin(), events.end());
        long long int ans = 0;
        for (long long int i = 0; i < n; i++)
        {
            long long int ind = (lower_bound(end.begin(), end.end(), events[i][1]) - end.begin()) - 1;
            if (ind >= 0)
                ans = max(ans, val[ind] + events[i][2]);
            else
                ans = max(ans, (long long int)events[i][2]);
            if (val.empty() || events[i][2] > val.back())
            {
                val.push_back(events[i][2]);
                end.push_back(events[i][0]);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}