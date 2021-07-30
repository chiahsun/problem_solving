class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        M = 10
        N = 1 << M
        for i in range(len(nums)):
            nums[i] = nums[i] + ((nums[nums[i]] % N) << M)
        for i in range(len(nums)):
            nums[i] >>= M
            
        return nums
