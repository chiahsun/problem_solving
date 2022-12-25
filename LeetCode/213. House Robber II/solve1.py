class Solution:
    def rob(self, nums: List[int]) -> int:
        a0, a1, N = 0, nums[0], len(nums)
        if N == 1:
            return nums[0]
        b0, b1 = nums[1], max(nums[1], a1)
        for i in range(2, N-1):
            a0, a1, b0, b1 = b0, b1, max(b0, a0+nums[i]), max(b1, a1+nums[i])
        if N > 2:
            b0, b1 = max(b0, a0+nums[N-1]), max(b1, a1)
        return max(b0, b1)
