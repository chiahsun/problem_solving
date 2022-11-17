class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        l, r = max(ax1, bx1), min(ax2, bx2)
        d, t = max(ay1, by1), min(ay2, by2)
        area = lambda w, h: w * h
        ans = area(ax2-ax1, ay2-ay1) + area(bx2-bx1, by2-by1)
        if r > l and t > d:
            ans -= area(r-l, t-d)
        return ans
