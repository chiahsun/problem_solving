class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = max(nums)+2
        offset = [0] * N
        for n in nums:
            offset[n+1] += 1
        for i in range(1, N):
            offset[i] += offset[i-1]
        for n in nums[:]:
            nums[offset[n]] = n
            offset[n] += 1
        
