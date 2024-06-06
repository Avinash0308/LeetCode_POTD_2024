#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return false;
        sort(hand.begin(), hand.end());
        vector<int> v(groupSize, 0);
        int iter = n / groupSize;
        for (int i = 0; i < iter; i++)
        {
            while (v[0] < n && hand[v[0]] == -1)
                v[0]++;
            if (v[0] == n)
                return false;
            int last = hand[v[0]];
            hand[v[0]] = -1;
            for (int j = 1; j < groupSize; j++)
            {
                v[j] = max(v[j], v[j - 1]);
                while (v[j] < n && (hand[v[j]] == -1 || hand[v[j]] <= last))
                    v[j]++;
                if (v[j] == n || hand[v[j]] != last + 1)
                    return false;
                last = hand[v[j]];
                hand[v[j]] = -1;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}