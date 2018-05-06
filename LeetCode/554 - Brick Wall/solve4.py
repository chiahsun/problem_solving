import queue

class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        d = collections.defaultdict(int)
        for row in wall:
            length = 0
            for brick in row:
                if length:
                    d[length] += 1
                length += brick
        
        return len(wall) - max(d.values() or [0])
