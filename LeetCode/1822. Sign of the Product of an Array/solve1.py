class Solution:
    def arraySign(self, nums: List[int]) -> int:
        sign = 1
        for a in nums:
            if a == 0:
                return 0
            elif a < 0:
                sign = -sign
        return sign
