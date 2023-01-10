#        abadbac
# c      abadba c
#        ab  ba
# a      abadb   a
# b      abad    b
# d      aba     d

# longest palindrome prefix
# aacecaaa  abcd  abadbac
# aacecaa   a     aba

# aacecaaa aaacecaa
# -0---01- aa
#           aa
#           aace  

# aaacecaa
#  aacecaaa 
# 01
#  0123456

# abadbac cabdaba
# ab       ab ab
# --0--0-  ab

# cabdaba
#     abadbac
# -01-012
class Solution:
    @staticmethod
    def longest_palindrome_prefix(s: str) -> str:
        N = len(s)
        fallback = [-1] * N
        for i in range(1, N):
            c, prev = s[i], fallback[i-1]
            while prev >= 0 and c != s[prev+1]:
                prev = fallback[prev]
            if c == s[prev+1]:
                fallback[i] = prev+1
        # print('s: ', s, 'fallback: ', fallback)
        pos = -1
        for c in reversed(s):
            while pos >= 0 and c != s[pos+1]:
                pos = fallback[pos]
            if c == s[pos+1]:
                pos += 1

        return s[:pos+1]


    def shortestPalindrome(self, s: str) -> str:
        lpp = Solution.longest_palindrome_prefix(s)
        # print('lpp: ', lpp)
        suffix = s[len(lpp):]
        return suffix[::-1] + lpp + suffix
