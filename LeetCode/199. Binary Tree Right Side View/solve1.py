# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        def traversal(p, res, depth=0):
            if depth == len(res):
                res.append(p.val)
            if p.right:
                traversal(p.right, res, depth+1)
            if p.left:
                traversal(p.left, res, depth+1)
            
        res = []
        if root:
           traversal(root, res)
        return res

