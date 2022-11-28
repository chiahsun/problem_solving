# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        A, p = [], head
        while p:
            A.append(p.val)
            p = p.next
        A.sort()
        p = head
        for i in range(len(A)):
            p.val = A[i]
            p = p.next
        return head
        
