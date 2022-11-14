class Solution:
    def longestPalindrome(self, s: str) -> int:
        s = list(s)
        s.sort()
        N, ans, add, i = len(s), 0, 0, 0
        while i < N:
            if i + 1 < N and s[i] == s[i+1]:
                ans += 2; i += 2
            else:
                add = 1; i += 1
        return ans + add
