class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        s = set()
        max_value = len(candies)//2
        for can in candies:
            if not can in s:
                s.add(can)
                if len(s) >= max_value:
                    return max_value
        
        return len(s)
