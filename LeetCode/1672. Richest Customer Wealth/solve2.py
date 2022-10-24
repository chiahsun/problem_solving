class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans = 0
        for i in range(0, len(accounts)):
            cur = 0
            for k in range(0, len(accounts[i])):
                cur += accounts[i][k]
            ans = max(ans, cur)
        return ans
