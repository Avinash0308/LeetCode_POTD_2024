from typing import List, Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        my_dict = {}
        for i in nums:
            my_dict[i] = 1
        res = ListNode()
        ans = res
        cur = head
        while cur != None:
            value = cur.val
            if not value in my_dict:
                res.next = ListNode(value)
                res = res.next
            cur = cur.next
        return ans.next
