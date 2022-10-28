# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        p = head
        ans = 0
        while p is not None:
            ans = (ans << 1) + p.val
            p = p.next
        return ans
