class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        st = []
        lefts = ['(', '[', '{']
        for i in range(len(s)):
            c = s[i]
            if c in lefts:
                st.append(c)
            else:
                reverse_c = '(' if c == ')' else ( '[' if c == ']' else '{' )
                if not st or st[-1] != reverse_c:
                    return False
                st.pop()
            if len(st) > (len(s)-i-1):
                return False
        return True
