class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        
        def map_to(s1, s2):
            d1, d2 = collections.defaultdict(str), collections.defaultdict(str)
            for i in range(len(s1)):
                c = s1[i]
                if not c in d1:
                    d1[c] = s2[i]
                elif d1[c] != s2[i]:
                    return False
            return True
                
        return map_to(s, t) and map_to(t, s)
