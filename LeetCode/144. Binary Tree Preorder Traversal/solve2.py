# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res, st = [], [root] if root is not None else []
    
        while st:
            a = st.pop()
            res.append(a.val)
            if a.right is not None:
                st.append(a.right)
            if a.left is not None:
                st.append(a.left)

        return res
