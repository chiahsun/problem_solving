class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        N, lo, cnt = len(grid[0]), 0, 0
        #  4  3  2 -1
        #  3  2  1 -1
        #  1  1 -1 -2
        # -1 -1 -2 -3
        for i in reversed(range(len(grid))):
            pos = bisect.bisect_right(grid[i], 0, lo=lo, key=lambda x: -x)
            lo = pos
            if lo == N:
                break
            cnt += N-pos
        return cnt
