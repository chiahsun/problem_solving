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
        def traverse(cur):
            if cur is None:
                return
            res.append(cur.val)
            for child in cur.children:
                traverse(child)
        traverse(root)
        return res
