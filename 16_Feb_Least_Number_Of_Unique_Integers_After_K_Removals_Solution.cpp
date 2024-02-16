#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (auto i : arr)
            mp[i]++;
        vector<int> val;
        for (auto i : mp)
            val.push_back(i.second);
        sort(val.begin(), val.end(), greater<int>());
        int n = val.size();
        for (int i = n - 1; i >= 0 && k; i--)
        {
            if (val[i] > k)
                return i + 1;
            k -= val[i];
            val.pop_back();
        }
        return val.size();
    }
};