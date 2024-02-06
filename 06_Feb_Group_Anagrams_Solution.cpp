#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> m;
        for (auto str : strs)
        {
            vector<int> count(26);
            for (auto c : str)
            {
                count[c - 'a']++;
            }
            m[count].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto anagram : m)
        {
            ans.push_back(anagram.second);
        }
        return ans;
    }
};