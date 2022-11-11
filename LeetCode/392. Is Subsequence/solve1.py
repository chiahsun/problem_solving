class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i, k, LS, LT = 0, 0, len(s), len(t)
        while (LS - i) <= (LT - k) and i < LS and k < LT:
            while k < LT and t[k] != s[i]:
                k += 1
            if k < LT and t[k] == s[i]:
                k += 1; i += 1
        return i == LS
