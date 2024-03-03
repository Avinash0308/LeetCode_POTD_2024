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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return NULL;
        int sz = 1;
        ListNode *a = head, *b = head->next;
        while (b && b->next)
        {
            sz++;
            a = a->next;
            b = b->next->next;
        }
        int cur_node = sz;
        sz = sz * 2 - (b == NULL);
        int rmv = sz - n + 1;
        ListNode *del;
        if (cur_node < rmv)
        {
            while (cur_node < rmv - 1)
            {
                a = a->next;
                cur_node++;
            }
            del = a->next;
            a->next = del->next;
        }
        else if (rmv == 1)
        {
            del = head;
            head = head->next;
        }
        else
        {
            cur_node = 1;
            a = head;
            while (cur_node < rmv - 1)
            {
                a = a->next;
                cur_node++;
            }
            del = a->next;
            a->next = a->next->next;
        }
        delete (del);
        return head;
    }
};