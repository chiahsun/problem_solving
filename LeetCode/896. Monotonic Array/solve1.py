class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        def get_sign(cur, nxt):
            return 0 if cur == nxt else (-1 if cur > nxt else 1)
        sign = 0
        for i in range(1, len(nums)):
            nxt_sign = get_sign(nums[i-1], nums[i])
            if sign == 0:
                sign = nxt_sign
            elif sign != 0 and nxt_sign != 0 and sign != nxt_sign:
                return False
        return True

