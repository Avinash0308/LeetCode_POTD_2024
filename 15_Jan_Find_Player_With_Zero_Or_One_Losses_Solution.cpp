#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> won, lost;
        for (auto i : matches)
        {
            won[i[0]]++;
            lost[i[1]]++;
        }
        vector<int> no_los;
        for (auto i : won)
        {
            if (lost.count(i.first) == 0)
                no_los.push_back(i.first);
        }
        vector<int> one_los;
        for (auto i : lost)
        {
            if (i.second == 1)
                one_los.push_back(i.first);
        }
        sort(no_los.begin(), no_los.end());
        sort(one_los.begin(), one_los.end());
        return {no_los, one_los};
    }
};