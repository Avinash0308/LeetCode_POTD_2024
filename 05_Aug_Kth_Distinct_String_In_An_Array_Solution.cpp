#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, pair<int, int>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.count(arr[i]) != 0)
            {
                mp[arr[i]].first++;
            }
            else
            {
                mp[arr[i]] = {1, i};
            }
        }
        vector<pair<int, string>> v;
        for (auto i : mp)
        {
            if (i.second.first == 1)
            {
                v.push_back({i.second.second, i.first});
            }
        }
        sort(v.begin(), v.end());
        if (v.size() < k)
            return "";
        else
            return v[k - 1].second;
    }
};

int main()
{
    return 0;
}