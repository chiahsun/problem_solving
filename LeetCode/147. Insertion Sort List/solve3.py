# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p, dummyHead = head, ListNode(0, None)
        while p:
            p2 = dummyHead
            while p2.next and p2.next.val < p.val:
                p2 = p2.next
            p2.next, p.next, p = p, p2.next, p.next
        return dummyHead.next

