# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(next=head)
        p = dummyHead
        while p.next:
            if p.next.next and p.next.val == p.next.next.val:
                val = p.next.val
                p2 = p.next
                while p2.next and p2.next.val == val:
                    p2 = p2.next
                p.next = p2.next
            else:
                p = p.next
        return dummyHead.next
