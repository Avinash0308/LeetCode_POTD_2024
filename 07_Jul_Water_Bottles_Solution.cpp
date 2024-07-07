#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int drink = numBottles;
        int empty = numBottles;
        while (empty >= numExchange)
        {
            int num = empty / numExchange;
            empty -= num * numExchange;
            drink += num;
            empty += num;
        }
        return drink;
    }
};

int main()
{
    return 0;
}