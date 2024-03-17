#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            if (newInterval[0] > intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                if (intervals[i][0] > newInterval[1])
                {
                    ans.push_back(newInterval);
                    while (i < n)
                    {
                        ans.push_back(intervals[i]);
                        i++;
                    }
                    return ans;
                }
                else
                {
                    newInterval[0] = min(newInterval[0], intervals[i][0]);
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    while (i + 1 < n && newInterval[1] >= intervals[i + 1][0])
                    {
                        i++;
                    }
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    ans.push_back(newInterval);
                    i++;
                    while (i < n)
                    {
                        ans.push_back(intervals[i]);
                        i++;
                    }
                    return ans;
                }
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};

int main()
{
    return 0;
}