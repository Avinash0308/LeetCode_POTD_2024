#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int anss = (m + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (anss < n || anss > 6 * n)
            return {};
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int val = (anss / (n - i)) + (anss % (n - i) != 0);
            ans.push_back(val);
            anss -= val;
        }
        return ans;
    }
};

int main()
{
    return 0;
}