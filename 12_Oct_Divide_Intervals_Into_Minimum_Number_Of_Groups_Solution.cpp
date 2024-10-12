#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        priority_queue<int, vector<int>, greater<int>> p;
        sort(intervals.begin(), intervals.end());
        for (auto i : intervals)
        {
            if (p.empty() || p.top() >= i[0])
            {
                p.push(i[1]);
            }
            else
            {
                p.pop();
                p.push(i[1]);
            }
        }
        return p.size();
    }
};

int main()
{
    return 0;
}