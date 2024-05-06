#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *prev = NULL, *next = NULL;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        head = reverse(head);
        ListNode *h = head;
        while (head->next)
        {
            if (head->next->val < head->val)
            {
                head->next = head->next->next;
            }
            else
            {
                head = head->next;
            }
        }
        return reverse(h);
    }
};

int main()
{
    return 0;
}