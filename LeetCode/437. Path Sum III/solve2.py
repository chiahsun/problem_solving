# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def traversal(p, prefixSum, resA):
            prefixSum.append(prefixSum[-1] + p.val)
            for i in range(len(prefixSum)-1):
                if prefixSum[-1] - prefixSum[i] == targetSum:
                    resA[0] += 1
            if p.left:
                traversal(p.left, prefixSum, resA)
            if p.right:
                traversal(p.right, prefixSum, resA)
            prefixSum.pop()
        resA = [0]
        if root:
            traversal(root, [0], resA)

        return resA[0]

