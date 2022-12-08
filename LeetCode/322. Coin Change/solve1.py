class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = 100000
        C = [INF] * (amount+1)
        C[0] = 0
        for i in range(1, len(C)):
            for c in coins:
                if i - c >= 0:
                    C[i] = min(C[i], C[i-c]+1)

        return -1 if C[amount] == INF else C[amount]
