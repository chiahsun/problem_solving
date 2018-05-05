class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        s = set(candies)
        
        return min(len(s), len(candies)//2)
