class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        demand = sorted(g)
        supply = sorted(s)
        
        i, k, used = 0, 0, 0
        while i < len(demand) and k < len(supply):
            if demand[i] > supply[k]:
                k += 1
            elif demand[i] <= supply[k]:
                i += 1
                k += 1
                used += 1
        
        return used

