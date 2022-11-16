class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        N = len(needle)
        for i in range(len(haystack)-N+1):
            if all(haystack[i+k] == needle[k] for k in range(N)):
                return i
        return -1
