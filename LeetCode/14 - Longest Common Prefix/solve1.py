class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
            
        max_len, i = -1, 0
        
        while max_len < 0:
            for k in range(len(strs)):
                if i >= len(strs[k]) or (k != 0 and strs[k][i] != strs[k-1][i]):
                    max_len = i
                    break
            i += 1
                
        return strs[0][:max_len]
