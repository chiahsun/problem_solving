class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        d = {}
        for can in candies:
            if can in d:
                ++d[can]
            else:
                d[can] = 1
        return min(len(d), len(candies)//2)
            
        
