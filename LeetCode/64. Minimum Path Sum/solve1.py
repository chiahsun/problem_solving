import queue

class Node:
    def __init__(self, position, distance):
        self.position = position
        self.distance = distance
    def __lt__(self, other):
        return self.distance < other.distance
    
class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        M, N = len(grid), len(grid[0])
        fixed = [[False] * N for _ in range(M)]
        dist = [[0x7FFFFFFF] * N for _ in range(M)]
        
        pq = queue.PriorityQueue()
        
        fixed[0][0] = True
        pq.put(Node([0, 0], grid[0][0]))
        
        while not pq.empty():
            first = pq.get()
            x, y = first.position[0], first.position[1]
            dist[x][y] = first.distance
            fixed[x][y] = True
            if x == M-1 and y == N-1:
                return dist[x][y]
            
            for dx, dy in zip([1, 0], [0, 1]):
                nx, ny = x+dx, y+dy
                if 0 <= nx < M and 0 <= ny < N and not fixed[nx][ny]:
                    new_distance = dist[x][y] + grid[nx][ny]
                    if new_distance < dist[nx][ny]:
                        pq.put(Node([nx, ny], new_distance))
                        
        return -1
