# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        
        p1 = head
        p2 = head.next
        
        while p1 != p2:
            if p2 == None or p2.next == None:
                return False
            p1 = p1.next
            p2 = p2.next.next
            
        return True


a = ListNode(1)
b = ListNode(2)
a.next = b

s = Solution()
print(s.hasCycle(a))
c = ListNode(3)
d = ListNode(4)
c.next = d
d.next = c
print(s.hasCycle(c))
print(s.hasCycle(d))
