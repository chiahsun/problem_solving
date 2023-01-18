class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        N, first = len(nums), nums[0]
        sumPos, maxPos, sumNeg, maxNeg = first, first, first, first
        for i in range(1, N):
            cur = nums[i]
            if sumPos < 0:
                sumPos = cur
            else:
                sumPos += cur
            maxPos = max(sumPos, maxPos)
            if sumNeg > 0:
                sumNeg = cur
            else:
                sumNeg += cur
            maxNeg = min(sumNeg, maxNeg)
        return max(maxPos, sum(nums) - maxNeg) if maxPos >= 0 else max(nums)
