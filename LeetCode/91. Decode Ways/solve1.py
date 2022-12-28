class Solution:
    def numDecodings(self, s: str) -> int:
        N = len(s)
        dp = [0] * N
        for i in reversed(range(N)):
            if s[i] == "0":
                continue
            dp[i] = dp[i+1] if i+1 < N else 1
            if 10 <= int(s[i:i+2]) <= 26:
                dp[i] += (dp[i+2] if i+2 < N else 1)
        return dp[0]

