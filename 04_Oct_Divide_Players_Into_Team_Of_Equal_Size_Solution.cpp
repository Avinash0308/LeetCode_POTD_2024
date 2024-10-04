#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        unordered_map<int, int> mp;
        long long sum = 0;
        long long n = skill.size();
        for (auto i : skill)
        {
            mp[i]++;
            sum += i;
        }
        if (sum % (n / 2))
            return -1;
        long long avg = sum / (n / 2);
        long long ans = 0;
        for (auto i : skill)
        {
            if (mp[i] == 0)
                continue;       
            if (mp[avg - i] == 0)
                return -1;
            ans += (avg - i) * i;
            mp[i]--;
            mp[avg - i]--;
        }
        return ans;
    }
};
int main()
{
    return 0;
}