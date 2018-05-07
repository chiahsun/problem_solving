class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        
        counts = [0] * (num+1)
        if len(counts) > 1:
            counts[1] = 1
        mask = 1
        for i in range(2, num+1):
            if (i-1) & i == 0: # power of 2
                counts[i] = 1
                mask = i-1
            else:
                counts[i] = counts[i & mask] + 1
        return counts
        
