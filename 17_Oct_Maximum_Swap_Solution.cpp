#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] > s[i - 1])
            {
                int j = i;
                char c = '0';
                int loc = i;
                while (j < s.size())
                {
                    if (c <= s[j])
                    {
                        loc = j;
                        c = s[j];
                    }
                    j++;
                }
                j = i;
                while (j > 0 && c > s[j - 1])
                    j--;
                swap(s[j], s[loc]);
                return stoi(s);
            }
        }
        return num;
    }
};

int main()
{
    return 0;
}