class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        lo, hi = 1, x // 2
        while lo < hi:
            mid = lo + (hi-lo) // 2
            if mid ** 2 > x:
                hi = mid-1
            else:
                if (mid+1) ** 2 > x:
                    lo = mid
                    break
                lo = mid+1
                
        return lo
