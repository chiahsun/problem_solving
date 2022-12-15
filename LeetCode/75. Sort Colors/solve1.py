class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        for i in range(N-1):
            min_pos, min_val = i, nums[i]
            for k in range(i+1, N):
                if nums[k] < min_val:
                    min_pos = k; min_val = nums[k]
            nums[i], nums[min_pos] = nums[min_pos], nums[i]
