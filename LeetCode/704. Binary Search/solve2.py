class Solution:
    def search(self, nums: List[int], target: int) -> int:
        pos = bisect_left(nums, target)
        if pos >= 0 and pos < len(nums) and nums[pos] == target:
            return pos
        return -1
