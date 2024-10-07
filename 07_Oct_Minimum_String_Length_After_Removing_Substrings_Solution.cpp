#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(string str)
    {
        stack<char> s;
        for (auto i : str)
        {
            if (!s.empty() && i == 'B' && s.top() == 'A')
                s.pop();
            else if (!s.empty() && i == 'D' && s.top() == 'C')
                s.pop();
            else
                s.push(i);
        }
        return s.size();
    }
};

int main()
{
    return 0;
}