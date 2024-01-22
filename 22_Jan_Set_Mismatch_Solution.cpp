#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        long long int n = nums.size();
        long long int cur_sum = accumulate(nums.begin(), nums.end(), 0);
        long long int actual_sum = (n * (n + 1)) / 2;
        long long int x_minus_y = cur_sum - actual_sum;
        long long int cur_square_sum = 0, actual_square_sum = 0;
        for (long long int i = 0; i < n; i++)
        {
            cur_square_sum += nums[i] * nums[i];
            actual_square_sum += (i + 1) * (i + 1);
        }
        long long int x2_minus_y2 = cur_square_sum - actual_square_sum;
        long long int x_plus_y = x2_minus_y2 / x_minus_y;
        int x = (x_plus_y + x_minus_y) / 2;
        int y = x_plus_y - x;
        return {x, y};
    }
};