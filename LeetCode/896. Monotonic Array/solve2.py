class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        return all(nums[i] - nums[i-1] >= 0 for i in range(1, len(nums))) or all(nums[i] - nums[i-1] <= 0 for i in range(1, len(nums)))
