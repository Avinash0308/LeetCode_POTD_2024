#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> ans(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--)
        {
            int cur = 0;
            int height = 0;
            for (int j = i; j < n; j++)
            {
                cur += books[j][0];
                height = max(height, books[j][1]);
                if (cur <= shelfWidth)
                {
                    int val = (j == n - 1) ? 0 : ans[j + 1];
                    ans[i] = min(ans[i], val + height);
                }
                else
                    j = n;
            }
        }
        return ans[0];
    }
};

int main()
{
    return 0;
}