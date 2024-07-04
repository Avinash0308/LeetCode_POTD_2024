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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ans = new ListNode(-1);
        ListNode *cur = ans;
        int x = 0;
        while (head->next)
        {
            while (head->next->val != 0)
            {
                x += head->next->val;
                head = head->next;
            }
            cur->next = new ListNode(x);
            cur = cur->next;
            head = head->next;
            x = 0;
        }
        return ans->next;
    }
};

int main()
{
    return 0;
}