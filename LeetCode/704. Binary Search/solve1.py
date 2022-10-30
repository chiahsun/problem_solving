class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums)-1
        while lo < hi:
            mid = lo + (hi-lo) // 2 
            if nums[mid] > target:
                hi = mid-1
            elif nums[mid] < target:
                lo = mid+1
            else:
                return mid
        return lo if lo == hi and target == nums[lo] else -1
