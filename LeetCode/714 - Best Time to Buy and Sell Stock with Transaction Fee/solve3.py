class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        release, hold = 0, -prices[0]
        for i in range(1, len(prices)):
            price = prices[i]
            release, hold = [max(release, hold + price-fee), max(release - price, hold)]
        return release
