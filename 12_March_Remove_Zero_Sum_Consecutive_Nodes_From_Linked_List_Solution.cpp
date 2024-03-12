#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        vector<int> input;
        unordered_map<int, int> m;
        long long int sum = 0;
        while (head)
        {
            sum += head->val;
            if (sum == 0)
            {
                while (!input.empty())
                {
                    m.erase(input.back());
                    input.pop_back();
                }
            }
            else if (m.count(sum) != 0)
            {
                while (input.back() != sum)
                {
                    m.erase(input.back());
                    input.pop_back();
                }
            }
            else
            {
                input.push_back(sum);
                m[sum] = 1;
            }
            head = head->next;
        }
        if (input.empty())
            return NULL;
        ListNode *ans = new ListNode(input[0]);
        head = ans;
        for (int i = 1; i < input.size(); i++)
        {
            head->next = new ListNode(input[i] - input[i - 1]);
            head = head->next;
        }
        return ans;
    }
};

int main()
{

    return 0;
}