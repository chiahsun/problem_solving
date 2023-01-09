class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        M, N = len(haystack), len(needle)
        fallback = [-1] * N
        for i in range(1, N):
            c, prev = needle[i], i-1
            while prev >= 0 and fallback[prev] >= 0:
                if c == needle[fallback[prev]+1]:
                    fallback[i] = fallback[prev]+1
                    break
                prev = fallback[prev]
            if fallback[i] < 0 and needle[0] == c:
                fallback[i] = 0

        pos = -1
        for i, c in enumerate(haystack):
            while pos >= 0 and c != needle[pos+1]:
                pos = fallback[pos]
            if c == needle[pos+1]:
                pos += 1
            if pos == N-1:
                return i-N+1

        return -1
