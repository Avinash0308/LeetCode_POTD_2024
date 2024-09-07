from typing import Optional
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def solve(cur: Optional[ListNode], root: Optional[TreeNode]) -> bool:
            if cur == None:
                return True
            if root == None:
                return False
            if cur.val == root.val:
                if solve(cur.next, root.left) or solve(cur.next, root.right):
                    return True
            return False
        if head == None:
            return True
        if root == None:
            return False
        if solve(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right):
            return True
        else:
            return False
