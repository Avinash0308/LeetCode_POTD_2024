#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int arr = 1;
        int a = points[0][0], b = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= b)
            {
                a = max(a, points[i][0]);
                b = min(b, points[i][1]);
            }
            else
            {
                arr++;
                a = points[i][0];
                b = points[i][1];
            }
        }
        return arr;
    }
};

int main()
{
    return 0;
}