#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int ind = -1;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (ch == word[i])
            {
                ind = i;
                break;
            }
        }
        int i = 0;
        while (i < ind)
        {
            swap(word[i], word[ind]);
            i++;
            ind--;
        }
        return word;
    }
};

int main()
{
    return 0;
}