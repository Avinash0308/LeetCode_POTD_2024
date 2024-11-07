#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestCombination(vector<int> &v)
    {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < 30; i++)
        {
            int cnt = 0;
            int val = 1 << i;
            for (int j = 0; j < n; j++)
            {
                if (val & v[j])
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main()
{
    return 0;
}