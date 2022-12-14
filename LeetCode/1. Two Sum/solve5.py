class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indices = sorted(list(range(len(nums))), key=lambda i: nums[i])
        lo, hi = 0, len(nums)-1
        while lo < hi:
            cur = nums[indices[lo]] + nums[indices[hi]]
            if cur == target:
                return [indices[lo], indices[hi]]
            if cur > target:
                hi -= 1
            else:
                lo += 1
        return []
        
