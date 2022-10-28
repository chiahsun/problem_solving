# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def search(p, now):
            nonlocal ans
            if p is not None:
                ans = max(ans, now)
                search(p.left, now+1)
                search(p.right, now+1)
        search(root, 1)
        return ans
