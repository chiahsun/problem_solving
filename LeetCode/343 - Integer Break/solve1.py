class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n+1)
        def sol(val):
            if dp[val]:
                return dp[val]
            for i in range(1, val//2+1):
                dp[val] = max(dp[val], max(i, sol(i)) * max(val-i, sol(val-i)))
                # print('  > dp[', val, ']: ', dp[val])
            # print('dp[', val, ']: ', dp[val])
            # print('dp: ', dp)
            return dp[val]
        
        return sol(n)
        
#s = Solution()
#print(s.integerBreak(3))
#print(s.integerBreak(4))
#print(s.integerBreak(8))
#print(s.integerBreak(58))
