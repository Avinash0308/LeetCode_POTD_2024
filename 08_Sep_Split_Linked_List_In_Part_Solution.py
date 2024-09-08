from typing import Optional,List
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length = 0
        x = head
        while x != None:
            length += 1
            x = x.next
        nex = None
        ans = []
        x = head
        while k:
            req = length//k
            if length % k:
                req += 1
            length -= req
            k -= 1
            ans.append(x)
            while x and req:
                nex = x
                x = x.next
                req -= 1
            if nex != None:
                nex.next = None
        return ans