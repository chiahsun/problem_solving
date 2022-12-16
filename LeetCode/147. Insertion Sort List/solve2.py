# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p, dummyHead = head, ListNode(-5001, None)
        while p:
            p2 = dummyHead
            oldNext = p.next
            while p2.next and p2.next.val < p.val:
                p2 = p2.next
            p2Next = p2.next
            p2.next = p
            p.next = p2Next
            p = oldNext

        return dummyHead.next

