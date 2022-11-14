class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lo, res = prices[0], 0
        for cur in prices:
            lo = min(cur, lo)
            res = max(res, cur - lo)
        return res

