# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p1, p2 = head, head
        while p2 is not None and p2.next is not None:
            p2 = p2.next
            if p2 is not None:
                p2 = p2.next
            p1 = p1.next
        return p1
