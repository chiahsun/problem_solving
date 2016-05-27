class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = list(s)
        begin, end, last_len, l = 0, 0, 0, len(s)
        
        while begin < l:
            while begin < l and s[begin] == ' ':
                begin += 1
            if begin >= l:
                break
            end = begin+1
            while end < l and s[end] != ' ':
                end += 1
            last_len = end - begin
            begin = end+1
        
        return last_len
