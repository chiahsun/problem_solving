#     100010
#     111122 lOnes
#     443211 rZeros
# For 000011 1+2-1
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        N = len(s)
        lOnes, rZeros = [0] * N, [0] * N
        for i in range(N):
            lOnes[i] = (lOnes[i-1] if i > 0 else 0) + (s[i] == '1')
            k = N-i-1
            rZeros[k] = (rZeros[k+1] if k < N-1 else 0) + (s[k] == '0')
        if lOnes[-1] == N or rZeros[0] == N:
            return 0
        minVal = N
        for i in range(N):
            minVal = min(minVal, lOnes[i] + rZeros[i]-1)
        return minVal
