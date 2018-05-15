# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):        
    def findNode(self, root, p):
        if root is None:
            return False
        if root == p:
            return True
        return self.findNode(root.left, p) or self.findNode(root.right, p)
    
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root is None or (root.left is None and root.right is None):
            return None
        a = self.lowestCommonAncestor(root.left, p, q)
        if a is not None:
            return a
        b = self.lowestCommonAncestor(root.right, p, q)
        if b is not None:
            return b
        return root if self.findNode(root, p) and self.findNode(root, q) else None
        
        
