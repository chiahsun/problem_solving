class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        hasItem = False
        curVal = 0
        for i in range(0, len(prices)):
            if not hasItem:
                if i+1 < len(prices) and prices[i+1] > prices[i]:
                    hasItem = True
                    curVal -= prices[i]
            else:
                if i + 1 == len(prices) or prices[i+1] < prices[i]:
                    hasItem = False
                    curVal += prices[i]

        return curVal
