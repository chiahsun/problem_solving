# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        firstHead, secondHead = head, head and head.next
        p1, p2 = firstHead, secondHead
        while p1 and p2:
            p1.next = p2.next
            if p1.next:
                p1 = p1.next
            p2.next = p1.next
            p2 = p2.next
        if p1:
            p1.next = secondHead
        return firstHead
        
