#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a++;
            if (s[i] == 'b')
                b++;
            if (s[i] == 'c')
                c++;
        }
        if (a < k || b < k || c < k)
            return -1;
        int ans = n;
        int left = n - 1, right = n;
        while (left >= 0)
        {
            if (s[left] == 'a')
                a--;
            if (s[left] == 'b')
                b--;
            if (s[left] == 'c')
                c--;
            left--;
            while (a < k || b < k || c < k)
            {
                right--;
                if (s[right] == 'a')
                    a++;
                if (s[right] == 'b')
                    b++;
                if (s[right] == 'c')
                    c++;
            }
            ans = min(ans, left + 1 + n - 1 - right + 1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}