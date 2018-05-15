# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        rhead = None
        while head is not None:
            val = head.val
            if rhead is None:
                rhead = ListNode(val)
            else:
                oldhead = rhead
                rhead = ListNode(val)
                rhead.next = oldhead
                
            head = head.next
        return rhead
            
        
