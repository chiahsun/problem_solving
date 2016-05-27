class Solution(object):
    d = {1 : "1"}
    
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        d = Solution.d
        if n in d:
            return d[n]
        
        s = self.countAndSay(n-1)
        
        i, cur, count = 0, s[0], 1
        say = ""
        
        while i < len(s):
            while i+1 < len(s) and s[i+1] == cur:
                count += 1
                i += 1
            say += (str(count) + str(cur))
            if i+1 == len(s):
                break
            else:
                i += 1
                cur = s[i]
                count = 1
        
        d[n] = say
        return say
