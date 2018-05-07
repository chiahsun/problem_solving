class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1, 10, 81]
        total = [dp[0], dp[1], dp[1]+dp[2]]
        while len(dp) <= n:
            nbits = max(0, 11 - len(dp))
            dp.append(dp[-1] * nbits)
            total.append(total[-1]+dp[-1])
        return total[n]
