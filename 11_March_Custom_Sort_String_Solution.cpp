#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> v(26);
        for (int i = 0; i < order.size(); i++)
        {
            v[order[i] - 'a'] = i + 1;
        }
        string fetch;
        vector<int> count(26);
        for (auto c : s)
        {
            if (v[c - 'a'] > 0)
            {
                count[c - 'a']++;
            }
            else
            {
                fetch.push_back(c);
            }
        }
        string an;
        for (auto c : order)
        {
            while (count[c - 'a'] > 0)
            {
                an.push_back(c);
                count[c - 'a']--;
            }
        }
        return an + fetch;
    }
};

int main()
{

    return 0;
}