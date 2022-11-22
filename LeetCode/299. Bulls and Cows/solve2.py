class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        d, A, B = defaultdict(int), 0, 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                A += 1
            else:
                B = B + (d[secret[i]] < 0) + (d[guess[i]] > 0)
                d[secret[i]] += 1
                d[guess[i]] -= 1
        return f'{A}A{B}B'
