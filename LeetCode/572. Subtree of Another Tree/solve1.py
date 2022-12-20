# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        def isSameTree(p, q):
            if not p or not q:
                return p == q
            return p.val == q.val and isSameTree(p.left, q.left) and isSameTree(p.right, q.right)

        return isSameTree(root, subRoot) or (root.left and self.isSubtree(root.left, subRoot)) or (root.right and self.isSubtree(root.right, subRoot))
            
