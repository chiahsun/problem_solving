class Solution:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        dp = [cost[0], cost[1]]
        for i in range(2, len(cost)):
            dp.append(min(dp[-1], dp[-2])+cost[i])
        return min(dp[-1], dp[-2])
