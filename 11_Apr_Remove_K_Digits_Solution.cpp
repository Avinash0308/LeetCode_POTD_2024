#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size())
            return "0";
        string ans;
        stack<char> s;
        for (auto c : num)
        {
            while (!s.empty() && s.top() > c && k)
            {
                s.pop();
                k--;
            }
            s.push(c);
        }
        char last = 'a';
        while (k && s.size() > 1)
        {
            k--;
            s.pop();
        }
        while (!s.empty())
        {
            char top = s.top();
            s.pop();
            ans.push_back(top);
        }
        while (ans.size() > 1 && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    return 0;
}