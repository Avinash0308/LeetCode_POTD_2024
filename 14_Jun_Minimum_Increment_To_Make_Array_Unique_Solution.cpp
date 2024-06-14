#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int len = 200002;
        vector<int> count(len, 0);
        for (auto i : nums)
        {
            count[i]++;
        }
        int ans = 0;
        for (int i = 0; i <= 200001; i++)
        {
            if (count[i])
            {
                ans += count[i] - 1;
                count[i + 1] += count[i] - 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}