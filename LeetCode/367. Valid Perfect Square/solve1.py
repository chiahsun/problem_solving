class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 0 or num == 1:
            return num
        lo, hi = 1, num // 2
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if mid ** 2 > num:
                hi = mid-1
            elif mid ** 2 < num:
                lo = mid+1
            else:
                return True
        return lo ** 2 == num
