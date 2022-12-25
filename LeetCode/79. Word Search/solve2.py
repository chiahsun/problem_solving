class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        M, N, q, W = len(board), len(board[0]), [], len(word)

       # https://stackoverflow.com/questions/5029934/defaultdict-of-defaultdict
        C = defaultdict(lambda: defaultdict(list))
        # C = [[[] for _ in range(N)] for _ in range(M)]
        def push_candidates():
            q = []
            for i in range(M):
                for k in range(N):
                    if board[i][k] == word[W-1]:
                        q.append((i, k))
                        C[i][k].append(W-1)
            pos = W-1
            while q and pos-1 >= 0:
                qn = []
                for x, y in q:    
                    for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                        nx, ny = x+dx, y+dy
                        if nx >= 0 and nx < M and ny >= 0 and ny < N and board[nx][ny] == word[pos-1] and pos-1 not in C[nx][ny]:
                            C[nx][ny].append(pos-1)
                            qn.append((nx, ny))
                q = qn
                pos -= 1

        def backtracking(x, y, pos):
            if pos+1 == W:
                return True
        
            board[x][y] = '-'
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and board[nx][ny] != '-' and board[nx][ny] == word[pos+1] and pos+1 in C[nx][ny]:
                    if backtracking(nx, ny, pos+1):
                        return True
            board[x][y] = word[pos]
            return False

        push_candidates()
        for i in range(M):
            for k in range(N):
                if board[i][k] == word[0] and backtracking(i, k, 0):
                    return True

        return False
