#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {arr[i], i};
        }
        sort(v.begin(), v.end());
        int rank = 1;
        for (int i = 0; i < n; i++)
        {
            arr[v[i].second] = rank;
            while (i < n - 1 && v[i].first == v[i + 1].first)
                arr[v[++i].second] = rank;
            rank++;
        }
        return arr;
    }
};

int main()
{
    return 0;
}