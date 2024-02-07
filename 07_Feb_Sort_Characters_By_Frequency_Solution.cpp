#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        vector<vector<int>> count(256);
        for (int i = 0; i < 256; i++)
            count[i] = {0, i};
        for (auto c : s)
        {
            count[(int)c][0]++;
        }
        sort(count.begin(), count.end(), greater<vector<int>>());
        string ans;
        for (int i = 0; i < 256; i++)
        {
            int val = count[i][0];
            while (val--)
            {
                ans.push_back(char(count[i][1]));
            }
        }
        return ans;
    }
};