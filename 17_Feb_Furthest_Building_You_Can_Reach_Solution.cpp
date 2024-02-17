#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> p;
        int pos = 0;
        while (pos < n - 1)
        {
            if (heights[pos] >= heights[pos + 1])
                pos++;
            else
            {
                int diff = heights[pos + 1] - heights[pos];
                bricks -= diff;
                p.push(diff);
                if (bricks < 0)
                {
                    if (ladders)
                    {
                        ladders--;
                        bricks += p.top();
                        p.pop();
                        pos++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                    pos++;
            }
        }
        return pos;
    }
};