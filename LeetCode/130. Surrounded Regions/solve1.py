class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        M, N = len(board), len(board[0])

        def dfs(board, x, y, t):
            board[x][y] = t
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and board[nx][ny] == 'O':
                    dfs(board, nx, ny, t)


        for i in range(M):
            if board[i][0] == 'O':
                dfs(board, i, 0, 'E')
            if board[i][N-1] == 'O':
                dfs(board, i, N-1, 'E')

        for i in range(N):
            if board[0][i] == 'O':
                dfs(board, 0, i, 'E')
            if board[M-1][i] == 'O':
                dfs(board, M-1, i, 'E')
        
        for i in range(M):
            for k in range(N):
                if board[i][k] == 'O':
                    board[i][k] = 'X'
                if board[i][k] == 'E':
                    board[i][k] = 'O'  
        


