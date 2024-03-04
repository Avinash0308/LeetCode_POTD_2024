#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int score = 0;
        int ans = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1;
        while (l <= r)
        {
            if (tokens[l] <= power)
            {
                power -= tokens[l];
                score++;
                l++;
            }
            else if (score >= 1)
            {
                power += tokens[r];
                r--;
                score--;
            }
            else
            {
                break;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};