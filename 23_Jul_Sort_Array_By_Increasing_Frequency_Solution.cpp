#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
    {
        if (a.second < b.second)
            return false;
        else
            return true;
    }
    else
        return false;
}
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto i : mp)
        {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
        {
            while (v[i].first)
            {
                ans.push_back(v[i].second);
                v[i].first--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}