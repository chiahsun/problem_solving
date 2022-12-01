# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def traversal(p, accuSum, d, resA):
            accuSum += p.val
            other = accuSum - targetSum
            if d[other] > 0:
                resA[0] += d[other]
            d[accuSum] += 1
            if p.left:
                traversal(p.left, accuSum, d, resA)
            if p.right:
                traversal(p.right, accuSum, d, resA)
            d[accuSum] -= 1
        d, resA = defaultdict(int), [0]
        d[0] = 1
        if root:
            traversal(root, 0, d, resA)

        return resA[0]

