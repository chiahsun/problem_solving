class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = len(s)
        for i in range(len(s)):
            for k, m in [(i-1, i+1), (i, i+1)]:
                while k >= 0 and m < len(s) and s[k] == s[m]:
                    count += 1
                    k -= 1
                    m += 1
        return count
