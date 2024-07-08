#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        while (q.size() > 1)
        {
            int len = q.size();
            int x = (len + (k % len) - 1) % len;
            while (x--)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

int main()
{
    return 0;
}