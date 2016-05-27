# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        def helper(v, cur, prefix):
            prefix = prefix + ("->" if prefix else "") + str(cur.val)
            if not cur.left and not cur.right:
                v.append(prefix)
            else:
                if cur.left:
                    helper(v, cur.left, prefix)
                if cur.right:
                    helper(v, cur.right, prefix)
        if not root:
            return []
        v = []
        helper(v, root, "")
        return v
