class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        st = []
        d = {'(' : ')', '[' : ']', '{' : '}'}
        for i in range(len(s)):
            c = s[i]
            if c in d:
                st.append(c)
            else:
                if not st or d[st.pop()] != c:
                    return False
            if len(st) > (len(s)-i-1):
                return False
        return True
