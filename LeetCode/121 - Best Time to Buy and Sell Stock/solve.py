class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        profit = 0
        vmin = prices[0]
        
        for p in prices:
            if p < vmin:
                vmin = p
            elif p - vmin > profit:
                profit = p - vmin
        return profit
