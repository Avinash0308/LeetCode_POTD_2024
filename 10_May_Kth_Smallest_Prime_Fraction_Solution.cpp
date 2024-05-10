#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> q;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            double val = double(arr[0]) / arr[i];
            q.push({val, double(0), double(i)});
        }
        while (k > 1)
        {
            vector<double> v = q.top();
            q.pop();
            int i = v[1], j = v[2];
            if (j - i > 1)
            {
                double val = double(arr[i + 1]) / arr[j];
                q.push({val, double(i + 1), double(j)});
            }
            k--;
        }
        int i = q.top()[1];
        int j = q.top()[2];
        return {arr[i], arr[j]};
    }
};

int main()
{
    return 0;
}