# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        def removeRecur(cur, n):
            if cur is None:
                return None, 0
            nextNode, nextN = removeRecur(cur.next, n)
            
            if nextN+1 == n:
                return nextNode, n
            
            cur.next = nextNode
            return cur, nextN+1
        
        newHead, headN = removeRecur(head, n)
        return newHead
