# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res, prev = [], []
        
        def traversal(p, prev, res, leftSum):
            if p is None:
                return
            prev.append(p.val)
            if leftSum == p.val and not p.left and not p.right:
                res.append(prev.copy())
            if p.left:
                traversal(p.left, prev, res, leftSum - p.val)
            if p.right:
                traversal(p.right, prev, res, leftSum - p.val)
            prev.pop()
        traversal(root, prev, res, targetSum)

        return res
