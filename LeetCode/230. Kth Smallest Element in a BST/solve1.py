# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        def traversal(p, k) -> (Optional[int], int):
            n_nodes = 0
            if p.left:
                val, left_n_nodes = traversal(p.left, k)
                if val is not None:
                    return val, 0
                n_nodes += left_n_nodes
            if k-n_nodes == 1:
                return p.val, 0
            n_nodes += 1
            if p.right:
                val, right_n_nodes = traversal(p.right, k-n_nodes)
                if val is not None:
                    return val, 0
                n_nodes += right_n_nodes
            return None, n_nodes
        return traversal(root, k)[0]
        
