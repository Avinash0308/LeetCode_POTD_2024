#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {heights[i], names[i]};
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            names[n - i - 1] = v[i].second;
        }
        return names;
    }
};

int main()
{
    return 0;
}