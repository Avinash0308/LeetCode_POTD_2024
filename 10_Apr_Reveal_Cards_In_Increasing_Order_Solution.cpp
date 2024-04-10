#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        queue<int> q;
        int n = deck.size();
        for (int i = 0; i < n; i++)
            q.push(i);
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        sort(deck.begin(), deck.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[ans[i]] = deck[i];
        }
        return res;
    }
};

int main()
{
    return 0;
}