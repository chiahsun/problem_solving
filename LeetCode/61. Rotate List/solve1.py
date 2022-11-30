# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        N, tail = 1, head
        while tail.next:
            N += 1; tail = tail.next
        k = k % N
        if N == 1 or k == 0:
            return head
        tail.next = head
        newHeadPrev = head
        for _ in range(N-k-1):
            newHeadPrev = newHeadPrev.next
        newHead = newHeadPrev.next
        newHeadPrev.next = None
        return newHead

