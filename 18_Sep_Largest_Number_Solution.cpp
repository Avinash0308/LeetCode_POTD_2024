#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(int a, int b)
    {
        string x = to_string(a);
        string y = to_string(b);
        return (x + y) > (y + x);
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        if (nums[0] == 0)
            return "0";
        for (auto i : nums)
        {
            ans += to_string(i);
        }
        return ans;
    }
};

int main()
{
    return 0;
}