class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        msb, res, mask = 1, 0, 0
        while msb <= left and msb <= right:
            if (msb & left) != (msb & right):
                mask = 0
            else:
                mask |= msb
            msb <<= 1
        if msb <= left or msb <= right:
            return 0
        return mask & left & right
