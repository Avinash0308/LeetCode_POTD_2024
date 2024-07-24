#include <bits/stdc++.h>
using namespace std;

vector<int> mapp;
class Solution
{
    static int get_map(int x)
    {
        int value = 1;
        if (x == 0)
            return mapp[0];
        int y = 0;
        while (x)
        {
            y += mapp[x % 10] * value;
            value *= 10;
            x /= 10;
        }
        return y;
    }
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        int x = get_map(a.first), y = get_map(b.first);
        if (x < y)
            return true;
        else if (x == y)
            return a.second < b.second;
        else
            return false;
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        mapp = mapping;
        vector<pair<int, int>> num;
        for (int i = 0; i < nums.size(); i++)
        {
            num.push_back({nums[i], i});
        }
        sort(num.begin(), num.end(), comp);
        for (int i = 0; i < num.size(); i++)
        {
            nums[i] = num[i].first;
        }
        return nums;
    }
};

int main()
{
    return 0;
}