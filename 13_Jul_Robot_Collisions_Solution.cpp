#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<vector<int>> robot(n);
        for (int i = 0; i < n; i++)
        {
            robot[i] = {positions[i], healths[i], (directions[i] == 'R') ? 0 : 1, i};
        }
        sort(robot.begin(), robot.end());
        stack<pair<int, int>> left, right;
        for (int i = 0; i < n; i++)
        {
            if (robot[i][2] == 0)
            {
                right.push({robot[i][1], robot[i][3]});
            }
            else
            {
                while (!right.empty() && robot[i][1] > right.top().first)
                {
                    right.pop();
                    robot[i][1]--;
                }
                if (!right.empty() && robot[i][1] == right.top().first)
                {
                    right.pop();
                }
                else if (!right.empty())
                {
                    if (robot[i][1])
                    {
                        right.top().first--;
                    }
                }
                else if (right.empty())
                {
                    if (robot[i][1])
                        left.push({robot[i][1], robot[i][3]});
                }
            }
        }
        vector<pair<int, int>> ansy;
        while (!left.empty())
        {
            ansy.push_back(left.top());
            left.pop();
        }
        while (!right.empty())
        {
            ansy.push_back(right.top());
            right.pop();
        }
        for (int i = 0; i < ansy.size(); i++)
        {
            int a = ansy[i].first, b = ansy[i].second;
            ansy[i].first = b;
            ansy[i].second = a;
        }
        sort(ansy.begin(), ansy.end());
        vector<int> res;
        for (auto i : ansy)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

int main()
{
    return 0;
}