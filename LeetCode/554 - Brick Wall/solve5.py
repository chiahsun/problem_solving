import queue

class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        d = collections.defaultdict(int)
        N = len(wall)
        min_cross = N
        for row in wall:
            length = 0
            for brick in row:
                if length:
                    d[length] += 1
                    min_cross = min(min_cross, N-d[length])
                    if min_cross == 0:
                        return min_cross
                length += brick
        
        return min_cross
