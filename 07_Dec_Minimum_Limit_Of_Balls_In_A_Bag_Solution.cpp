#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int count(long long int mid, vector<int> &v)
    {
        long long int cnt = 0;
        for (auto i : v)
        {
            cnt += (i - 1) / mid;
        }
        return cnt;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        long long int low = 1, high = 1e9;
        while (low <= high)
        {
            long long int mid = (low + high) / 2;
            if (count(mid, nums) <= maxOperations)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main()
{
    return 0;
}