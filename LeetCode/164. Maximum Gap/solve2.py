class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        i, M, N = 1, max(nums), len(nums)
        while i <= M:
            zeros, ones = [], []
            for n in nums:
                if n & i:
                    ones.append(n)
                else:
                    zeros.append(n)
            nums = zeros + ones
            i <<= 1

        res = 0
        for i in range(1, N):
            res = max(res, nums[i]-nums[i-1])
        return res
            
