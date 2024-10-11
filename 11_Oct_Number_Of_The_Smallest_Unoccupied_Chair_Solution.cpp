#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int target)
    {
        vector<vector<int>> time;
        int n = times.size();
        for (int i = 0; i < n; i++)
        {
            time.push_back({times[i][0], times[i][1], i});
        }
        sort(time.begin(), time.end());
        vector<int> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qp;
        int last = -1;
        int occ = 0;
        for (int i = 0; i < n; i++)
        {
            while (!qp.empty() && qp.top().first <= time[i][0])
            {
                pq.push(qp.top().second);
                qp.pop();
            }
            if (pq.empty())
            {
                last = occ;
                occ++;
            }
            else
            {
                last = pq.top();
                pq.pop();
            }
            qp.push({time[i][1], last});
            ans[time[i][2]] = last;
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return ans[target];
    }
};

int main()
{
    return 0;
}