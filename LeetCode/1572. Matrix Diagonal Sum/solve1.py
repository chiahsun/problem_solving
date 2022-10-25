class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        ans = 0
        N = len(mat)
        for i in range(N):
            ans += mat[i][i]
            ans += mat[i][N-i-1]
        if N % 2 == 1:
            ans -= mat[N // 2][N // 2]
        return ans
