from typing import Optional
import math
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur.next != None:
            x = cur.val
            y = cur.next.val
            z = math.gcd(x,y)
            cur.next = ListNode(z,cur.next)
            cur = cur.next.next
        return head
        