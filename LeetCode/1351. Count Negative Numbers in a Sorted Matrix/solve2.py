class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        N = len(grid[0])
        i, cnt = N-1, 0
        for row in grid:
            while i >= 0 and row[i] < 0:
                i -= 1
            cnt += (N - i - 1)
        return cnt
