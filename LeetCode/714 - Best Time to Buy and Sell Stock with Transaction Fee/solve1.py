class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        dp = [[0, 0] for _ in range(len(prices))]
        dp[0][1] = -prices[0]
        for i in range(1, len(dp)):
            price = prices[i]
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price-fee)
            dp[i][1] = max(dp[i-1][0] - price, dp[i-1][1])
        return dp[-1][0]
