class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        
        last_end = -0x7FFFFFFF
        pairs.sort(key = lambda x: x[1])
        
        count = 0
        for pair in pairs:
            print(pair)
            if pair[0] > last_end:
                last_end = pair[1]
                count += 1
                print(count)
        return count
        
s = Solution()
print(s.findLongestChain([[1,2], [2,3], [3,4]]))
print(s.findLongestChain([[9,10],[-4,9],[-5,6],[-5,9],[8,9]]))
