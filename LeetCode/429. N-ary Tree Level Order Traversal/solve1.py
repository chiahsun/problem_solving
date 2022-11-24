"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        q, res = [root] if root else [], []
        while q:
            qn = []
            res.append(q)
            for n in q:
                if n.children:
                    qn.extend(n.children)
            q = qn
        return map(lambda xs: map(lambda x: x.val, xs), res)
