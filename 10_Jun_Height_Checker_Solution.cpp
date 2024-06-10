#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> x = heights;
        sort(heights.begin(), heights.end());
        int n = x.size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (heights[i] != x[i]);
        }
        return count;
    }
};

int main()
{
    return 0;
}