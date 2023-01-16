#   a b c d e
# a 1 1 1 1 1
# c 1 1 2 2 2
# e 1 1 2 2 3

#   b a c
# a 0 1 1
# c 0 1 2
# e 0 1 2

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        M, N = len(text1), len(text2)
        dp = [[0] * (N+1) for _ in range(M+1)]
        for i, c1 in enumerate(text1):
            for k, c2 in enumerate(text2):
                dp[i+1][k+1] = max(dp[i+1][k], dp[i][k+1], dp[i][k] + (1 if c1 == c2 else 0))
        return dp[-1][-1]
