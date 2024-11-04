#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        string ans;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (i < n - 1 && word[i] == word[i + 1] && cnt < 9)
            {
                cnt++;
                i++;
            }
            ans += to_string(cnt) + word[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}