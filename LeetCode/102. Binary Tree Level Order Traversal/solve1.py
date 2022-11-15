# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = [[root], []] if root else [[], []]
        ans = []
        while q[0]:
            ans.append(list(map(lambda x: x.val, q[0])))
            for c in q[0]:
                if c.left:
                    q[1].append(c.left)
                if c.right:
                    q[1].append(c.right)
            q[0], q[1] = q[1], []
                      
        return ans
