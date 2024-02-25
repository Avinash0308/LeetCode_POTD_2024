#include <bits/stdc++.h>
using namespace std;
class Solution
{
    unordered_map<int, vector<int>> prime_to_index;
    unordered_map<int, vector<int>> index_to_prime;
    void dfs(int ind, unordered_map<int, int> &visitedPrime, vector<int> &visited)
    {
        if (visited[ind])
            return;
        visited[ind] = 1;
        for (auto prime : index_to_prime[ind])
        {
            if (visitedPrime.count(prime) != 0)
                continue;
            visitedPrime[prime] = 1;
            for (auto index : prime_to_index[prime])
            {
                dfs(index, visitedPrime, visited);
            }
        }
    }

public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int val = nums[i];
            for (int j = 2; j * j <= nums[i]; j++)
            {
                if (val % j == 0)
                {
                    prime_to_index[j].push_back(i);
                    index_to_prime[i].push_back(j);
                    while (val % j == 0)
                        val /= j;
                }
            }
            if (val > 1)
            {
                prime_to_index[val].push_back(i);
                index_to_prime[i].push_back(val);
            }
        }
        unordered_map<int, int> visitedPrime;
        vector<int> visited(n);
        dfs(0, visitedPrime, visited);
        for (auto visit : visited)
            if (!visit)
                return false;
        return true;
    }
};