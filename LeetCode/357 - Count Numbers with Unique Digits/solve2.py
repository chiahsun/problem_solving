class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1, 10, 81] + [0] * 8
        total = [dp[0], dp[1], dp[1]+dp[2]] + [0] * 8
        for i in range(3, 11):
            dp[i] = dp[i-1] * (11 - i)
            total[i] = total[i-1] + dp[i]
            
        return total[n] if n < len(total) else total[-1]
