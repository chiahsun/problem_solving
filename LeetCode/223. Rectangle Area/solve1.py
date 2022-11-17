class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        def computeDistance(r, l):
            return 0 if r <= l else r - l
        w = computeDistance(min(C, G), max(A, E))
        h = computeDistance(min(D, H), max(B, F))
        
        return -(w*h) + (G-E) * (H-F) + (C-A) * (D-B)
