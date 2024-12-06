#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_map<int, int> mp;
        for (auto i : banned)
        {
            if (i <= n)
                mp[i]++;
        }
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i])
                continue;
            if (sum + i <= maxSum)
                cnt++, sum += i;
            else
                return cnt;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}