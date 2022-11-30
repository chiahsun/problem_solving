# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead, p1, p2, carry = ListNode(), l1, l2, 0
        p = dummyHead
        while carry > 0 or p1 or p2:
            carry += (p1.val if p1 else 0)
            carry += (p2.val if p2 else 0)
            newNode = ListNode(val=carry % 10)
            p.next = newNode
            p = p.next; p1 = p1 and p1.next; p2 = p2 and p2.next
            carry //= 10
        return dummyHead.next
