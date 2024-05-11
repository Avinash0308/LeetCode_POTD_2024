#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        vector<pair<double, int>> ratio;
        int n = quality.size();
        for (int i = 0; i < n; i++)
        {
            ratio.push_back({(double)wage[i] / quality[i], i});
        }
        sort(ratio.begin(), ratio.end());
        priority_queue<int> pq;
        int qua = 0;
        double maxRate = 0.0;
        for (int i = 0; i < k; i++)
        {
            qua += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            pq.push(quality[ratio[i].second]);
        }
        double res = maxRate * qua;
        for (int i = k; i < n; i++)
        {
            maxRate = max(maxRate, ratio[i].first);
            qua -= pq.top();
            pq.pop();
            pq.push(quality[ratio[i].second]);
            qua += quality[ratio[i].second];
            res = min(res, maxRate * qua);
        }
        return res;
    }
};

int main()
{
    return 0;
}