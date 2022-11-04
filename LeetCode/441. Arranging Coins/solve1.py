class Solution:
    def arrangeCoins(self, n: int) -> int:
        def f(k):
            return (k+1) * k // 2
        
        return bisect.bisect_left(range(0, n+1), 1, key=lambda x: 1 if f(x) == n or f(x+1) > n else 0)
