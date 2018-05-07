class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        dp = [0, -prices[0]]
        next_dp = [0, 0]
        for i in range(1, len(prices)):
            price = prices[i]
            next_dp = [max(dp[0], dp[1] + price-fee), max(dp[0] - price, dp[1])]
            dp = next_dp
        return dp[0]
