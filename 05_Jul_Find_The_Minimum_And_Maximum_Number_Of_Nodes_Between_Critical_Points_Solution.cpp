#include <bits/stdc++.h>
using namespace std;

/**
 Definition for singly-linked list.
 */
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        if (!head || !head->next)
            return {-1, -1};
        ListNode *h = head->next, *prev = head;
        vector<int> ans = {INT_MAX, INT_MIN};
        int first = -1, last = -1;
        int ind = 1;
        while (h->next)
        {
            if ((prev->val < h->val && h->val > h->next->val) || (prev->val > h->val && h->val < h->next->val))
            {
                if (first == -1)
                    first = ind;
                else
                {
                    ans[0] = min(ans[0], ind - last);
                    ans[1] = max(ans[1], ind - first);
                }
                last = ind;
            }
            prev = h;
            h = h->next;
            ind++;
        }
        if (ans[0] == INT_MAX)
            return {-1, -1};
        else
            return ans;
    }
};

int main()
{
    return 0;
}