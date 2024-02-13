#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto word : words)
        {
            int low = 0, high = word.size() - 1, pos = 1;
            while (low <= high && pos)
            {
                if (word[low] != word[high])
                {
                    pos = 0;
                }
                low++;
                high--;
            }
            if (pos)
                return word;
        }
        return "";
    }
};