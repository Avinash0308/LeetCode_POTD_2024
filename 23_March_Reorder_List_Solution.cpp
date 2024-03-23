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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = slow;
        ListNode *cur = slow->next;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode *start = head;
        ListNode *end = prev;
        while (start != end)
        {
            ListNode *nextS = start->next;
            ListNode *nextE = end->next;
            start->next = end;
            end->next = nextS;
            end = nextE;
            start = nextS;
        }
        start->next = NULL;
        return;
    }
};

int main()
{
    return 0;
}