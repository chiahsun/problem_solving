# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def traverse(p: TreeNode) -> (bool, int, int):
            min_val, max_val = p.val, p.val
            if p.left:
                ok, minl, maxl = traverse(p.left)
                if not ok or maxl >= p.val:
                    return (False, 0, 0)
                min_val = minl
            if p.right:
                ok, minr, maxr = traverse(p.right)
                if not ok or minr <= p.val:
                    return (False, 0, 0)
                max_val = maxr
            return (True, min_val, max_val)
        if root:
            return traverse(root)[0]
        return False
