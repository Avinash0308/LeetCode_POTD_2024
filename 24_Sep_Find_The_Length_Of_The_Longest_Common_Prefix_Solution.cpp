#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<string, int> mp;
        int ans = 0;
        for (auto i : arr1)
        {
            string x = to_string(i);
            int n = x.size();
            while (n--)
            {
                mp[x]++;
                x.pop_back();
            }
        }
        for (auto i : arr2)
        {
            string x = to_string(i);
            int n = x.size();
            while (n--)
            {
                if (mp.count(x) != 0)
                    ans = max(ans, n + 1);
                x.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}