# daabcbaabcbc
# da---
#      ba---
#           bc

# ababac   abac
# abab
# 0123
#
#   abab
#   0123

# ababac
# --012-
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        st, prefix_cnt, N = [], [], len(part)

        fallback = [-1] * N
        for i in range(1, N):
            c, prev = part[i], fallback[i-1]
            while prev >= 0 and c != part[prev+1]:
                prev = fallback[prev]
            if c == part[prev+1]:
                fallback[i] = prev+1

        for c in s:
            already_added = False

            if prefix_cnt:
                prev = prefix_cnt[-1]
                while prev != -1 and c != part[prev+1]:
                    prev = fallback[prev]

                if c == part[prev+1]:
                    prefix_cnt.append(prev+1)
                    already_added = True

            if not already_added and c == part[0]:
                prefix_cnt.append(0)
   
            st.append(c)
            if prefix_cnt and prefix_cnt[-1] == N-1:
                st = st[:-N]
                prefix_cnt = prefix_cnt[:-N]
        return "".join(st)

