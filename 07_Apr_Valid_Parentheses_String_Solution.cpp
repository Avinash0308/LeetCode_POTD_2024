#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> star;
        stack<int> open;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open.push(i);
            else if (s[i] == '*')
                star.push(i);
            else
            {
                if (open.empty() && star.empty())
                    return false;
                if (open.empty())
                    star.pop();
                else
                    open.pop();
            }
        }
        while (!(open.empty()))
        {
            if (star.empty() || star.top() < open.top())
                return false;
            star.pop();
            open.pop();
        }
        return true;
    }
};

int main()
{
    return 0;
}