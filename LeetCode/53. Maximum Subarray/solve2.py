class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res, prevSum = nums[0], nums[0]
        for i in range(1, len(nums)):
            cur = nums[i]
            if prevSum > 0:
                prevSum += cur
            else:
                prevSum = cur
            res = max(res, prevSum)
        return res
