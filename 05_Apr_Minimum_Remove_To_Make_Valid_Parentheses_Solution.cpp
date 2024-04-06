#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans;
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')')
            {
                if (!(st.empty()))
                    st.pop();
                else
                    s[i] = '-';
            }
        }
        while (!st.empty())
        {
            s[st.top()] = '-';
            st.pop();
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}