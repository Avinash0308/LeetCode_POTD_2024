#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ans = 0;
        int ind = -1;
        int ele = *max_element(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele)
            {
                count++;
            }
            while (count > k)
            {
                if (nums[ind + 1] == ele)
                    count--;
                ind++;
            }
            if (count == k)
            {
                int sec = ind + 1;
                while (nums[sec] != ele)
                    sec++;
                ans += sec + 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}