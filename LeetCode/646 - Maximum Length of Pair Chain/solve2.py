import collections

class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        points = set()
        chains = collections.defaultdict(int) 
        for start, end in pairs:
            points.add(start)
            points.add(end)
            if not start in chains or end < chains[start] :
                chains[start] = end

        points = list(points)
        points.sort()
        points.append(points[-1]+1)
        dp = [0] * len(points)
        
        pos = {point: idx for idx, point in enumerate(points)}
        
        for i in range(len(points)):
            cur_point = points[i]
            if i > 0:
                dp[i] = max(dp[i-1], dp[i])
            
            if cur_point in chains:
                next_start_pos = pos[chains[cur_point]]+1
                if next_start_pos < len(dp):
                    dp[next_start_pos] = max(dp[next_start_pos], dp[i]+1)
        return dp[-1]

