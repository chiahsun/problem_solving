class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        N, M = len(heights), len(heights[0])
        P = [[False for _ in range(M)] for _ in range(N)]
        A = [[False for _ in range(M)] for _ in range(N)]
        def dfs(x, y, mat):
            mat[x][y] = True
            for dx, dy in zip([0, 0, 1, -1], [1, -1, 0, 0]):
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < N and ny >= 0 and ny < M and (not mat[nx][ny]) and heights[x][y] <= heights[nx][ny]:
                    dfs(nx, ny, mat)
        for x in range(0, N):
            for y in range(0, M):
                if not P[x][y] and (x == 0 or y == 0):
                    dfs(x, y, P) 
        for x in range(0, N):
            for y in range(0, M):
                if not A[x][y] and (x == N-1 or y == M-1):
                    dfs(x, y, A) 
        l = []
        for x in range(0, N):
            for y in range(0, M):
                if P[x][y] and A[x][y]:
                    l.append((x, y))
        return l

