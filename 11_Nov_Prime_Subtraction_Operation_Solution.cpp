#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        vector<int> v(1001);
        for (int i = 2; i * i <= 1000; i++)
        {
            if (v[i])
                continue;
            for (int j = i * i; j <= 1000; j += i)
            {
                v[j] = i;
            }
        }
        for (int i = 2; i <= 1000; i++)
        {
            if (v[i] == 0)
                v[i] = i;
            else
                v[i] = v[i - 1];
        }
        int prev = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (prev >= nums[i])
                return false;
            nums[i] -= v[nums[i] - prev - 1];
            prev = nums[i];
        }
        return true;
    }
};

int main()
{
    return 0;
}