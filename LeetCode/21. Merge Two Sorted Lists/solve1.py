# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        p, q = list1, list2
        dummy = ListNode()
        cur = dummy
        while p is not None or q is not None:
            if p is None:
                cur.next = q
                cur = q
                break
            elif q is None:
                cur.next = p
                cur = p
                break
            else:
                if min(p.val, q.val) == p.val:
                    cur.next = p
                    cur = p
                    p = p.next
                else:
                    cur.next = q
                    cur = q
                    q = q.next
        return dummy.next

