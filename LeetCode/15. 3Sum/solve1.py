class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        N, res =  len(nums), set()
        indices = sorted(list(range(N)), key=lambda i: nums[i])
        for mid in range(N):
            mid_val, lo, hi = nums[indices[mid]], 0, N-1
            while lo >= 0 and lo < mid < hi and hi < N:
                lo_val, hi_val = nums[indices[lo]], nums[indices[hi]]
                cur = lo_val + mid_val + hi_val
                if cur == 0:
                    res.add((lo_val, mid_val, hi_val))
                if cur > 0:
                    hi -= 1
                else:
                    lo += 1
        return list(map(lambda t: [t[0], t[1], t[2]], res))
