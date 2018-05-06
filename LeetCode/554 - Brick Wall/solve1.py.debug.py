class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        N = len(wall)
        print('N: ', N)
        pos = [0] * N
        left = [wall[i][0] for i in range(N)]
        min_count = N
        while True: 
            min_value = min(left)
            
            zero_cnt = 0
            total = 0
            print(left, '+++ min_value: ', min_value)
            for i in range(N):
                #print('Enter range')
                left[i] -= min_value
                #print('  ', 'left[', i, ']: ', left[i])
                if left[i] == 0:
                    zero_cnt += 1
                    pos[i] += 1
                    #print('pos[', i, ']: ', pos[i])
                    left[i] = wall[i][pos[i]] if pos[i] < len(wall[i]) else 0
                    total += left[i]
            #print("total: ", total)
            if total == 0:
                return min_count
            min_count = min(min_count, N-zero_cnt)
            print('min_count', min_count)
            print(left, '---')
            if min_count == 0:
                return min_count
        return N

s = Solution()
#print(s.leastBricks([[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]))
print(s.leastBricks([[7,1,2],[3,5,1,1],[10]]))
