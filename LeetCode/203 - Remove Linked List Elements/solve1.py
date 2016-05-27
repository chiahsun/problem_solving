class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        prev = ListNode(0)
        prev.next = head
        dummy_head = prev
        
        while prev:
            while prev.next and prev.next.val == val:
                prev.next = prev.next.next
            prev = prev.next
        return dummy_head.next
