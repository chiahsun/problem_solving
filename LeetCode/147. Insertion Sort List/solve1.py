# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p = head
        reversedHead = ListNode(5001, None)
        while p:
            p2 = reversedHead
            oldNext = p.next
            while p2.next and p2.next.val > p.val:
                p2 = p2.next
            p2Next = p2.next
            p2.next = p
            p.next = p2Next
            p = oldNext

        p = reversedHead
        tail = reversedHead.next
        p1, p2 = reversedHead, reversedHead.next
        while p2:
            p3 = p2.next
            p2.next = p1
            p1, p2 = p2, p3
        tail.next = None
        return p1

