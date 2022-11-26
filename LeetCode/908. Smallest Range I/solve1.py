class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        d = max(nums) -  min(nums) - 2 * k
        return d if d > 0 else 0
