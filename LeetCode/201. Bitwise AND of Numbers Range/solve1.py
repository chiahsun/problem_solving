class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        mask, res = 1, 0
        while (mask<<1) <= left or (mask<<1) <= right:
            mask <<= 1
        while mask and (mask & left == mask & right):
            if mask & left or mask & right:
                res |= mask  
            mask >>= 1
        return res
