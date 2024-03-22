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
    int sizeoflist(ListNode *head)
    {
        int size = 0;
        while (head)
        {
            head = head->next;
            size++;
        }
        return size;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head || !(head->next))
            return true;
        int size = sizeoflist(head);
        int moves = (size / 2) - 1;
        ListNode *left = head, *right = head->next;
        left->next = NULL;
        while (moves--)
        {
            ListNode *prev = left;
            left = right;
            right = right->next;
            left->next = prev;
        }
        if (size % 2)
            right = right->next;
        while (left)
        {
            if (left->val != right->val)
                return false;
            right = right->next;
            left = left->next;
        }
        return true;
    }
};

int main()
{
    return 0;
}