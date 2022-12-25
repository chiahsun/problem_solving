class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        M, N, q, W = len(board), len(board[0]), [], len(word)
        
        def backtracking(x, y, pos):
            if pos+1 == W:
                return True
            board[x][y] = '-'
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and board[nx][ny] != '-' and board[nx][ny] == word[pos+1]:
                    if backtracking(nx, ny, pos+1):
                        return True
            board[x][y] = word[pos]
            return False
                        
        for i in range(M):
            for k in range(N):
                if board[i][k] == word[0] and backtracking(i, k, 0):
                    return True

        return False

