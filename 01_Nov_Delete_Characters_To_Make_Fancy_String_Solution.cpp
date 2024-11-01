#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans;
        for (auto c : s)
        {
            if (ans.size() >= 2)
            {
                if (ans[ans.size() - 1] == c && ans[ans.size() - 2] == c)
                    continue;
                else
                    ans.push_back(c);
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}