class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        N = len(nums)
        skip = [i+1 for i in range(N)]
        for i in range(N-2, -1, -1):
            if nums[i] == nums[i+1]:
                skip[i] = skip[i+1]
        res, i = [], 0
        while i < N-3:
            ii = nums[i]
            k = i+1
            while k < N-2:
                kk = nums[k]
                m = k+1
                while m < N-1:
                    mm = nums[m]
                    other = target - nums[i] - nums[k] - nums[m]
                    pos = bisect_right(nums, other)
                    pos -= 1
                    if pos <= m:
                        break
                    if pos < N and nums[pos] == other:
                        res.append([nums[i], nums[k], nums[m], nums[pos]])
                    m = skip[m]
                k = skip[k]
            i = skip[i]
        return res
