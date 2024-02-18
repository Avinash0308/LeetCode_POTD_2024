#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<long long int> rooms(n);
        set<long long int> s;
        for (long long int i = 0; i < n; i++)
            s.insert(i);
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> time;
        for (auto meet : meetings)
        {
            while (!(time.empty()) && time.top().first <= meet[0])
            {
                s.insert(time.top().second);
                time.pop();
            }
            long long int val, end;
            if (!(s.empty()))
            {
                val = *(s.begin());
                end = meet[1];
                s.erase(s.begin());
            }
            else
            {
                val = time.top().second;
                end = time.top().first - meet[0] + meet[1];
                time.pop();
            }
            rooms[val]++;
            time.push({end, val});
        }
        long long int ans = 0, ind;
        for (long long int i = 0; i < n; i++)
        {
            if (ans < rooms[i])
            {
                ans = rooms[i];
                ind = i;
            }
        }
        return ind;
    }
};