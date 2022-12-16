class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0_end, p1_end = 0, 0
        for i, n in enumerate(nums):
            if n != 2:
                if p1_end < i:
                    nums[i], nums[p1_end] = nums[p1_end], nums[i]
                p1_end += 1
                if n == 0:
                    i = p1_end - 1
                    if p0_end < p1_end:
                        nums[i], nums[p0_end] = nums[p0_end], nums[i]
                    p0_end += 1

