#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (auto i : arr)
        {
            if (i < 0)
            {
                mp[(k - (abs(i % k))) % k]++;
            }
            else
                mp[i % k]++;
        }
        for (auto i : mp)
        {
            if (i.first == 0 && i.second % 2)
                return false;
            if (i.second != mp[(k - i.first) % k])
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}