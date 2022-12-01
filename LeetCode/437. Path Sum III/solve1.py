# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def traversal(p, sums, resA):
            for i in range(len(sums)):
                sums[i] += p.val
            sums.append(p.val)
            for s in sums:
                # print('sums: ', sums, ' s: ', s)
                if s == targetSum:
                    resA[0] += 1
            if p.left:
                traversal(p.left, sums, resA)
            if p.right:
                traversal(p.right, sums, resA)
            sums.pop()
            for i in range(len(sums)):
                sums[i] -= p.val
        resA = [0]
        if root:
            traversal(root, [], resA)

        return resA[0]

