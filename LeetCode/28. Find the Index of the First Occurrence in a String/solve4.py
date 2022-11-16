class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        N, prev, pos = len(needle), -1, -1
        fallback = [-1] * N
        for i in range(1, N):
            while prev >= 0 and needle[i] != needle[prev+1]:
                prev = fallback[prev]
            if needle[i] == needle[prev+1]:
                prev += 1
            fallback[i] = prev
        for i, c in enumerate(haystack):
            while pos >= 0 and needle[pos+1] != c:
                pos = fallback[pos]
            if pos >= 0 or needle[0] == c:
                pos += 1
            if pos == N-1:
                return i-N+1
        return -1
