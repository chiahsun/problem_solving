class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        M, N = len(mat), len(mat[0])
        R = [[-1] * N for _ in range(M)]
        q = []
        for i in range(M):
            for k in range(N):
                if mat[i][k] == 0:
                    R[i][k] = 0
                    q.append((i, k))
        d = 0
        while q:
            qn = []
            for x, y in q:
                for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                    nx, ny = x+dx, y+dy
                    if nx >= 0 and nx < M and ny >= 0 and ny < N and R[nx][ny] == -1:
                        R[nx][ny] = d+1
                        qn.append((nx, ny))
            q = qn
            d += 1
        return R
