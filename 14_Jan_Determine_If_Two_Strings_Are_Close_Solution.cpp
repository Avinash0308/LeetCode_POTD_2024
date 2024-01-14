#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        vector<int> wod1(26), wod2(26);
        for (auto i : word1)
            wod1[i - 'a']++;
        for (auto i : word2)
            wod2[i - 'a']++;
        for (int i = 0; i < 26; i++)
            if (((wod1[i] != 0) + (wod2[i] != 0)) % 2)
                return false;
        sort(wod1.begin(), wod1.end());
        sort(wod2.begin(), wod2.end());
        return wod1 == wod2;
    }
};