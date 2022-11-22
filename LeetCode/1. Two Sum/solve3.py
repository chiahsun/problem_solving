class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {nums[0]: 0}
        for i in range(1, len(nums)):
            cur = nums[i]
            prev = target - cur
            if prev in d:
                return [d[prev], i]
            d[cur] = i
        return []
