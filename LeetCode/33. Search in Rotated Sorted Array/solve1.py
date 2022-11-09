class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # 4 5 6 7 0 1  2
        # 4 5 6 7 8 9 10
        m, first, cur = max(nums), nums[0], target
        if cur < first:
            cur = target + m + 1
        pos = bisect_left(nums, cur, key=lambda x: x if x >= first else x + m + 1)
        if pos < len(nums) and nums[pos] == target:
            return pos
        return -1
            
