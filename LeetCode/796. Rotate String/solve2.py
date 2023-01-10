# ababac cababa
# --012-
#         ababa
#
#        abacab
#        aba
#          a
#           -
#            ab
#
#        acabab
#        a
#         -abab
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal) or sorted(s) != sorted(goal):
            return False
        
        N = len(s)
        fallback = [-1] * N
        for i in range(1, N):
            c, prev = s[i], fallback[i-1]
            while prev >= 0 and c != s[prev+1]:
                prev = fallback[prev]
            if c == s[prev+1]:
                fallback[i] = prev+1

        pos = -1
        for i, c in enumerate(goal):
            while pos >= 0 and c != s[pos+1]:
                pos = fallback[pos]
            if c == s[pos+1]:
                pos += 1
        start = N-pos-1

        for i in range(N):
            if s[i] != goal[(start+i) % N]:
                return False
        return True
