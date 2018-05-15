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
        st = []
        while head is not None:
            st.append(head.val)
            head = head.next
        first = cur = None
        while st:
            x = st[-1]
            st.pop()
            if first is None:
                first = cur = ListNode(x)
            else:
                cur.next = ListNode(x)
                cur = cur.next
        return first
            
        
