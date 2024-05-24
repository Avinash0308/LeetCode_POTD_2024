#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int ind, int cur, unordered_map<char, int> &availability, int &ans, vector<string> &words, vector<int> &score)
    {
        if (ind == words.size())
        {
            ans = max(ans, cur);
            return;
        }
        solve(ind + 1, cur, availability, ans, words, score);
        int pos = 1;
        int value = 0;
        for (auto c : words[ind])
        {
            availability[c]--;
            value += score[c - 'a'];
            if (availability[c] < 0)
                pos = 0;
        }
        if (pos)
            solve(ind + 1, cur + value, availability, ans, words, score);
        for (auto c : words[ind])
        {
            availability[c]++;
        }
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        unordered_map<char, int> availability;
        for (auto characters : letters)
            availability[characters]++;
        int ans = 0;
        solve(0, 0, availability, ans, words, score);
        return ans;
    }
};

int main()
{
    return 0;
}