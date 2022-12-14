class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, n in enumerate(nums):
            other = target-n
            if other in d:
                return [d[other], i]
            d[n] = i
        return []
        
