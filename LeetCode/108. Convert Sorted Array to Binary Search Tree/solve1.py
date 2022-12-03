# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:

        def toBST(nums, lo, hi):
            mid, left, right = (lo+hi)//2, None, None
            if lo < mid:
                left = toBST(nums, lo, mid-1)
            if hi > mid:
                right = toBST(nums, mid+1, hi)

            return TreeNode(val=nums[mid], left=left, right=right)

        return toBST(nums, 0, len(nums)-1)
            
