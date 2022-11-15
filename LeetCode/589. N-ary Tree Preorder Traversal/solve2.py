"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        q = [root] if root else []
        ans = []
        while q:
            f = q[0]; q = q[1:]
            q = f.children + q
            ans.append(f.val)

        return ans
