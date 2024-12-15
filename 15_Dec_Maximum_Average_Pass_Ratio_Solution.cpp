#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<vector<double>> pq;
        for (auto i : classes)
        {
            double a = i[0];
            double b = i[1];
            double cur = a / b;
            double cha = (a + 1) / (b + 1);
            pq.push({cha - cur, a + 1, b + 1});
        }
        while (extraStudents--)
        {
            vector<double> i = pq.top();
            pq.pop();
            double cur = i[1] / i[2];
            double cha = (i[1] + 1) / (i[2] + 1);
            pq.push({cha - cur, i[1] + 1, i[2] + 1});
        }
        double ans = 0;
        while (!pq.empty())
        {
            vector<double> i = pq.top();
            pq.pop();
            ans += (i[1] - 1) / (i[2] - 1);
        }
        return ans / n;
    }
};
int main()
{
    return 0;
}