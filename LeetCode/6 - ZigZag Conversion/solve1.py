class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1:
            return s
            
        rows = [ [] for _ in range(numRows) ]
        
        r, dr= 0, 1
        
        for i in range(len(s)):
            rows[r].append(s[i])
            if r == 0:
                dr = 1
            elif r == numRows-1:
                dr = -1
            r += dr
        
        return "".join([c for r in rows for c in r])
