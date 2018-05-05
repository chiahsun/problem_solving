class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        total = 0
        for a1, a2 in points: # Iter through elements directly
            m = collections.defaultdict(int) # Use default value 0 when needed 
            for b1, b2 in points: # Since "all pairwise distinct"
                dis = (a1-b1)**2 + (a2-b2)**2 # Use ** for power
                m[dis] += 1
            
            for dis, count in m.items():
                total += (count * (count-1))
        return total
