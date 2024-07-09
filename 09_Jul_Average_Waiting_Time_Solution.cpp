#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double wait = 0;
        int last = 0, n = customers.size();
        for (auto i : customers)
        {
            last = max(last, i[0]);
            last += i[1];
            wait += last - i[0];
        }
        return wait / n;
    }
};

int main()
{
    return 0;
}