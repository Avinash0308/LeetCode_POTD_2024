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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *ans = NULL;
        ListNode *next = NULL;
        while (head)
        {
            next = head->next;
            head->next = ans;
            ans = head;
            head = next;
        }
        return ans;
    }
};

int main()
{
    return 0;
}