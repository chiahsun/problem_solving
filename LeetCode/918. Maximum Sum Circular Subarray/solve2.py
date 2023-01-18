class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        normalPreSum, normalMax, N = 0, nums[0], len(nums)
        prefixSum, suffixPrevSum, suffixSum, specialMax = 0, 0, [0] * N, nums[0]
        for i in reversed(range(N)):
            suffixPrevSum += nums[i]
            suffixSum[i] = max(suffixSum[i+1] if i < N-1 else suffixPrevSum, suffixPrevSum)
        for i in range(N):
            cur = nums[i]
            normalPreSum = max(0, normalPreSum) + cur
            normalMax = max(normalMax, normalPreSum)
            prefixSum += cur
            specialMax = max(specialMax, prefixSum + (suffixSum[i+1] if i < N-1 else 0))
        
        return max(normalMax, specialMax)

