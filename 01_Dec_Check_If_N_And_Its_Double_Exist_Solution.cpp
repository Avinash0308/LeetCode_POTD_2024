#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (auto i : arr)
        {
            if (mp.count(i * 2))
                return true;
            if (i % 2 == 0 && mp.count(i / 2))
                return true;
            mp[i]++;
        }
        return false;
    }
};

int main()
{
    return 0;
}