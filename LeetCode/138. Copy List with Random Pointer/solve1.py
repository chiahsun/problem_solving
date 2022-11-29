"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        newHead = Node(x=head.val)
        d, p1 = {None: None, head: newHead}, head
        p2 = newHead
        while p1.next:
            p1 = p1.next
            p2.next = Node(x=p1.val)
            p2 = p2.next
            d[p1] = p2
        p1, p2 = head, newHead
        while p1:
            p2.random = d[p1.random]
            p1 = p1.next
            p2 = p2.next
        return newHead

