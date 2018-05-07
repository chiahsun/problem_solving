class Solution:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        max_value = 1000000
        cost.append(0)
        dp = [max_value] * (len(cost))
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(0, len(cost)):
            for k in [1, 2]:
                if i+k < len(cost):
                    dp[i+k] = min(dp[i+k], dp[i]+cost[i+k])
        return dp[-1]
        
