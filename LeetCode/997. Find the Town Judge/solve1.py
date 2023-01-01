class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        T, F = [0] * n, [0] * n
        for e in trust:
            a, b = e[0]-1, e[1]-1
            T[a] += 1
            F[b] += 1
        for i in range(n):
            if T[i] == 0 and F[i] == n-1:
                return i+1
        return -1

