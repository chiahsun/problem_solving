class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        
        def get_int(s, pos):
            i, k = pos, pos
            while k < len(s) and s[k] != '.':
                k += 1
            res = 0 if (i == k) else int(s[i:k])
            if k < len(s) and s[k] == '.':
                k += 1
            return res, k
            
        i, k = 0, 0
        
        while i < len(version1) or k < len(version2):
            a, i = get_int(version1, i)
            b, k = get_int(version2, k)
            if a < b:
                return -1
            elif b < a:
                return 1
            
        return 0    

