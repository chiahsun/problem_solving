class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        a = [0] + [1] * (n)
        for i in range(m-1):
            for k in range(n):
                a[k+1] += a[k]
        return a[-1]
