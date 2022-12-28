class Solution:
    def longestPalindrome(self, s: str) -> str:
        begin, end, N = 0, 1, len(s)
        def is_palindrome(i, k):
            if k >= N:
                return False, 0, 0
            ii, kk = i, k
            while ii < kk:
                if s[ii] != s[kk]:
                    return False, 0, 0
                ii += 1; kk -= 1
            while i-1 >= 0 and k+1 < N and s[i-1] == s[k+1]:
                i -= 1; k += 1
            return True, i, k
    
        for i in range(N):
            for c in [i, i+1]:
                ok, f, t = is_palindrome(i, c)
                if ok and t-f >= end-begin:
                    begin, end = f, t+1
        return s[begin:end]
