class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        a, b = nums[0], max(nums[0], nums[1] if len(nums) > 1 else nums[0])
        for i in range(2, len(nums)):
            a, b = b, max(b, nums[i]+a)
        return max(a, b)
