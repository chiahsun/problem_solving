import queue

class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        d = collections.defaultdict(int)
        max_length = 0
        for row in wall:
            length = 0
            for brick in row:
                length += brick
                d[length] += 1
                max_length = max(max_length, length)
        
        del d[max_length]
        
        return len(wall) - (max(d.values()) if d else 0)
