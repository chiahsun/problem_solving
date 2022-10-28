# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        def search(p, left):
            if p is None:
                return 0
            if left and p.left is None and p.right is None:
                return p.val
            return search(p.left, True) + search(p.right, False)
        return search(root, False) 

