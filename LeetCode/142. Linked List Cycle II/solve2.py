# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head and head.next
        fast = slow and slow.next
        while fast and fast != slow:
            slow = slow.next
            fast = fast.next and fast.next.next
        slow, slow2 = fast, head
        while slow and slow != slow2:
            slow = slow.next
            slow2 = slow2.next
        return slow

