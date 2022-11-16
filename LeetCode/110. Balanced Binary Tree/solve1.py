# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def traverse(p) -> (bool, int):
            l_depth, r_depth, ok = 0, 0, True
            if p.left:
                ok, l_depth = traverse(p.left)
            if ok and p.right:
                ok, r_depth = traverse(p.right)
            return (ok and abs(l_depth - r_depth) <= 1, max(l_depth, r_depth)+1)
        return not root or traverse(root)[0]
            
