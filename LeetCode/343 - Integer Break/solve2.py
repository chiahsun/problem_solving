class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n+1)
        for val in range(2, n+1):
            for i in range(1, val//2+1):
                dp[val] = max(dp[val], max(i, dp[i]) * max(val-i, dp[val-i]))
        
        return dp[-1]
