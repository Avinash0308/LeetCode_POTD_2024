#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[score[i]] = i;
        }
        sort(score.begin(), score.end());
        if (n > 0)
            ans[mp[score[n - 1]]] = "Gold Medal";
        if (n > 1)
            ans[mp[score[n - 2]]] = "Silver Medal";
        if (n > 2)
            ans[mp[score[n - 3]]] = "Bronze Medal";
        for (int i = 0; i < n - 3; i++)
        {
            ans[mp[score[i]]] = to_string(n - i);
        }
        return ans;
    }
};

int main()
{
    return 0;
}