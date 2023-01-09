# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def traversal(p):
            if p is not None:
                res.append(p.val)
                traversal(p.left)
                traversal(p.right)
        traversal(root)
        return res
        
