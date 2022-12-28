class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        i, N, res = 0, len(nums), 0
        while i+2 < N:
            begin, d = i, nums[i+1]-nums[i]
            i += 1
            if nums[i+1]-nums[i] != d:
                continue
            i += 1
            while i+1 < N and nums[i+1]-nums[i] == d:
                i += 1
            k = i-begin-1
            res += ((k+1) * k // 2)
        return res

