class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        lo, hi = 0, len(nums)-1
        while lo < hi:
            mid = (lo+hi) // 2
            mid_val, lo_val, hi_val = nums[mid], nums[lo], nums[hi]
            max_val = max(lo_val, mid_val, hi_val)
            if max_val == mid_val:
                if nums[mid+1] >= mid_val:
                    lo = mid+1
                else:
                    hi = mid
            elif max_val == lo_val:
                hi = mid
            else:
                lo = mid+1
        return lo
