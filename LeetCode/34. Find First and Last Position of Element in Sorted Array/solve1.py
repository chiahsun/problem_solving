class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = bisect_left(nums, target)
        if left == -1 or left >= len(nums) or nums[left] != target:
            return [-1, -1]
        right = bisect_right(nums, target)
        return [left, right-1]
