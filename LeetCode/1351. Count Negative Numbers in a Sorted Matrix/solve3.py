class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        N = len(grid[0])
        k, i, cnt = 0, N-1, 0
        while k < len(grid):
            while i >= 0 and grid[k][i] < 0:
                i -= 1
            if i < 0:
                break
            cnt += (N - i - 1)
            k += 1
        cnt += (len(grid) - k) * N
        return cnt
