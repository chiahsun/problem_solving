class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        d = {}
        max_value = len(candies)//2
        for can in candies:
            if can in d:
                ++d[can]
            else:
                d[can] = 1
                if len(d) >= max_value:
                    return max_value
        
        return len(d)
            
        
