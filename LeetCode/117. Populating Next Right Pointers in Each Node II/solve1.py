"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        first = root
        while first:
            p = first; first = None
            cur = None
            while p:
                childs = []
                if p.left:
                    childs.append(p.left)
                if p.right:
                    childs.append(p.right)
                for c in childs:
                    if not first:
                        first = c
                    if cur:
                        cur.next = c
                    cur = c
                p = p.next
        return root
                
