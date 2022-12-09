# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isSymmetricSubTree(p, q):
            if p is None or q is None:
                return p is None and q is None
            if p.val != q.val:
                return False
            return isSymmetricSubTree(p.left, q.right) and isSymmetricSubTree(p.right, q.left)

        return isSymmetricSubTree(root.left, root.right)

