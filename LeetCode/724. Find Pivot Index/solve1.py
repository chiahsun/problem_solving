class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        l, r = 0, total
        for i in range(len(nums)):
            l += nums[i-1] if i > 0 else 0
            r -= nums[i]
            if l == r:
                return i
        return -1

