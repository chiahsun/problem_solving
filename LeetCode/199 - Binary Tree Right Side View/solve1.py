# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        
        def dfs(cur, level):
            nonlocal ans
            if level >= len(ans):
                ans.append(cur.val)
                
            if cur.right:
                dfs(cur.right, level+1)
                
            if cur.left:
                dfs(cur.left, level+1)
                
        if root:
            dfs(root, 0)
        return ans
