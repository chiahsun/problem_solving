"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []
        def search(p):
            if p:
                res.append(p.val)
                if p.children:
                    for c in p.children:
                        search(c)
        search(root)
        return res
