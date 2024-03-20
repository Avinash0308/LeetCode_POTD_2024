#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *cur = list1;
        int ind = 0;
        while (ind < a - 1)
        {
            cur = cur->next;
            ind++;
        }
        ListNode *before_a = cur;
        while (ind < b)
        {
            cur = cur->next;
            ind++;
        }
        ListNode *after_a = cur->next;
        cur->next = NULL;
        before_a->next = list2;
        cur = list2;
        while (cur->next)
            cur = cur->next;
        cur->next = after_a;
        return list1;
    }
};

int main()
{
    return 0;
}