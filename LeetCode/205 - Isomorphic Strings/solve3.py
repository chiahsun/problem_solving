class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        d1, d2 = collections.defaultdict(str), collections.defaultdict(str)
        for i in range(len(s)):
            x, y = s[i], t[i]
            if not x in d1 and not y in d2:
                d1[x] = y
                d2[y] = x
            elif d1[x] != y or d2[y] != x:
                return False
        return True
