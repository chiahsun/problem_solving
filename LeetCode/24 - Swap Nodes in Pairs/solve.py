# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        p1, p2 = head, head.next
        newHead = p2
        
        while p1 and p2:
            p3 = p2.next
            p4 = p3.next if p3 else None
            p2.next = p1
            p1.next = p4 if p4 else p3
            p1 = p3
            p2 = p4
        return newHead
        
