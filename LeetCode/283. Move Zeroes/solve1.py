class Solution:

    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        p0, p1 = 0, 0
        def find() -> bool:
            nonlocal p0, p1
            while  p0 < N and nums[p0] != 0:
                p0 += 1
            if p0 == N:
                return True
            p1 = max(p1, p0+1)
            while p1 < N and nums[p1] == 0:
                p1 += 1
            if p1 == N:
                return True
            return False
        while not find():
            # print("now: ", nums, 'swap: ', p0, p1)
            nums[p0], nums[p1] = nums[p1], nums[p0]
            p0 += 1
            p1 += 1
        return nums
