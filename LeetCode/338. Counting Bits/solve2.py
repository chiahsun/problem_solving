class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        
        counts = [0] * (num+1)
        mask = 1
        for i in range(1, num+1):
            if (i-1) & i == 0: # power of 2
                mask = i-1
            counts[i] = counts[i & mask] + 1
        return counts
        
