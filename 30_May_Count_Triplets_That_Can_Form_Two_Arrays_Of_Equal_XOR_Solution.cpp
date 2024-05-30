#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            for (int j = i; j < n; j++)
            {
                a ^= arr[j];
                int b = 0;
                for (int k = j + 1; k < n; k++)
                {
                    b ^= arr[k];
                    if (a == b)
                        ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}