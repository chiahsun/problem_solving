class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        N = len(s)
        dp = [False] * N
        for wd in wordDict:
            l = len(wd)
            if N >= l and s[-l:] == wd:
                dp[-l] = True
        for i in reversed(range(N)):
            if not dp[i]:
                for wd in wordDict:
                    l = len(wd)
                    if i+l < N and dp[i+l] and s[i:i+l] == wd:
                        dp[i] = True
                        break
        return dp[0]
