class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        tail = len(s)
        
        while tail-1 >= 0 and s[tail-1] == ' ':
            tail -= 1
        begin = tail-1 if tail > 0 else 0
        
        while begin-1 >= 0 and s[begin-1] != ' ':
            begin -= 1
            
        return tail - begin
