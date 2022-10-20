class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while n > 0:
            if n & 0x1 > 0:
                cnt += 1
            n >>= 1
        return cnt
