# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def merge_sort(p):
            if not p or not p.next:
                return p
            if not p.next.next:
                if p.val > p.next.val:
                    p.val, p.next.val = p.next.val, p.val
                return p
            slow, fast = p, p and p.next and p.next
            while slow and fast and fast.next:
                slow = slow.next
                fast = fast.next and fast.next.next
            p1, p2 = p, slow and slow.next
            if slow:
                slow.next = None
            p1 = merge_sort(p1)
            p2 = merge_sort(p2)
            dummyHead = ListNode()
            p = dummyHead
            while p1 or p2:
                if not p2 or (p1 and p1.val <= p2.val):
                    p.next = p1; p = p1; p1 = p1 and p1.next
                else:
                    p.next = p2; p = p2; p2 = p2 and p2.next
            return dummyHead.next
        return merge_sort(head)
