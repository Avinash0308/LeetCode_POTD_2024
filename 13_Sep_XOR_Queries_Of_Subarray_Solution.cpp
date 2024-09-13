#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            arr[i] ^= arr[i - 1];
        }
        vector<int> ans;
        for (auto i : queries)
        {
            int val = arr[i[1]] ^ ((i[0] > 0) ? arr[i[0] - 1] : 0);
            ans.push_back(val);
        }
        return ans;
    }
};

int main()
{
    return 0;
}