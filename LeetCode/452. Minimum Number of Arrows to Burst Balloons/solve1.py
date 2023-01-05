class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        last, N, res = None, len(points), 0
        L = list(range(N))
        L.sort(key=lambda i: points[i][1])
        for i in range(N):
            cur = points[L[i]]
            if last is not None and cur[0] <= last:
                continue
            last = cur[1]
            res += 1

        return res
