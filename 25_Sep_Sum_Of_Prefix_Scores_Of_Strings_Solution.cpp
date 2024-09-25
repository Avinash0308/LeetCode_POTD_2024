#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    int data;
    unordered_map<char, Trie *> mp;
    Trie()
    {
        data = 0;
    }
};
class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trie *t = new Trie();
        for (auto i : words)
        {
            Trie *x = t;
            for (auto j : i)
            {
                if (x->mp.count(j) == 0)
                {
                    x->mp[j] = new Trie();
                }
                x = x->mp[j];
                x->data++;
            }
        }
        vector<int> ans(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
        {
            Trie *x = t;
            for (auto j : words[i])
            {
                x = x->mp[j];
                ans[i] += x->data;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}