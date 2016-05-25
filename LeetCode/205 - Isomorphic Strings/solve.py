class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s, t = list(s), list(t)
        if len(s) != len(t):
            return False
            
        used = [False] * 128
        m = [None] * 128
        
        for i in range(len(s)):
            a, b = ord(s[i]), ord(t[i])
            if not m[a]:
                if used[b]:
                    return False
                else:
                    m[a] = b
                    used[b] = True
            else:
                if m[a] != b:
                    return False
        return True
