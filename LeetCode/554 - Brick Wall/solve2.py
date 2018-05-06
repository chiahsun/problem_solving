import queue

class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        min_cross = N = len(wall)
        pos = [1] * N
        pq = queue.PriorityQueue()
        
        for i in range(N):
            pq.put((wall[i][0], i)) # length, row pos
        
        nnow = min_val = 0
        while not pq.empty():
            top = pq.get()
            
            top_length, top_row_pos = top[0], top[1]
            if top_length != min_val:
                min_val = top_length
                nnow = 1
            else:
                nnow += 1           
            last = pos[top_row_pos] >= len(wall[top_row_pos])
            if not last:
                next_length = top_length + wall[top_row_pos][pos[top_row_pos]]
                pq.put((next_length, top_row_pos))
                pos[top_row_pos] += 1 
            
                min_cross = min(min_cross, N-nnow)
                # print('length ', top_length, " row pos ", top_row_pos, ' min_cross ', min_cross)
                if min_cross == 0:
                    return 0
        return min_cross
            
# s = Solution()
# print(s.leastBricks([[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]))

