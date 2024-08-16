#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int a = INT_MIN, b = INT_MIN, ind = -1;
        int n = arrays.size();
        for (int i = 0; i < n; i++)
        {
            if (arrays[i].back() >= a)
            {
                b = a;
                ind = i;
                a = arrays[i].back();
            }
            else if (arrays[i].back() > b)
            {
                b = arrays[i].back();
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ind)
            {
                ans = max(ans, abs(arrays[i][0] - b));
            }
            else
            {
                ans = max(ans, abs(arrays[i][0] - a));
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}