# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        d = {}
        def get_depth(p) -> int:
            nonlocal d
            if not p in d:
                d[p] = max(get_depth(p.left), get_depth(p.right))+1 if p else 0
            return d[p]
        get_depth(root)

        def get_passed_nodes(p):
            return max(get_depth(p.left) + get_depth(p.right)+1, 
                       get_passed_nodes(p.left) if p.left else 0,
                       get_passed_nodes(p.right) if p.right else 0)

        return get_passed_nodes(root)-1
