#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int ans = 0;
        stack<int> s;
        for (auto i : tokens)
        {
            if (i == "*" || i == "/" || i == "+" || i == "-")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (i == "*")
                    s.push(a * b);
                else if (i == "/")
                    s.push(a / b);
                else if (i == "-")
                    s.push(a - b);
                else
                    s.push(a + b);
            }
            else
            {
                int val = stoi(i);
                s.push(val);
            }
        }
        return s.top();
    }
};