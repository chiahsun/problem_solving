class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        def slope_order(p, origin):
            if p[0] - origin[0] == 0:
                return float("inf") if p[1] - origin[1] > 0 else float("-inf")
            return (p[1] - origin[1])/(p[0] - origin[0])


        res = 1
        for origin in points:
            preSlope = None
            points.sort(key=lambda p: slope_order(p, origin))
            cnt = 1
            for p in points:
                if p != origin:
                    curSlope = slope_order(p, origin)
                    if curSlope == preSlope:
                        cnt += 1
                    else:
                        cnt = 2
                        preSlope = curSlope
                    res = max(res, cnt)

        return res
