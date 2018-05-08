class Solution:
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        
        def dfs(r, c):
            if board[r][c] == 'M':
                board[r][c] = 'X'
            elif board[r][c] == 'E':
                n_adj_mines = 0
                for dx in range(-1, 2):
                    for dy in range(-1, 2):
                        if dx != 0 or dy != 0:
                            x, y = r+dx, c+dy
                            if 0 <= x < len(board) and 0 <= y < len(board[0]):
                                if board[x][y] == 'M':
                                    n_adj_mines += 1
                if n_adj_mines != 0:
                    board[r][c] = str(n_adj_mines)
                else:
                    board[r][c] = 'B'
                    for dx in range(-1, 2):
                        for dy in range(-1, 2):
                            if dx != 0 or dy != 0:
                                x, y = r+dx, c+dy
                                if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == 'E':
                                    dfs(x, y)
        dfs(click[0], click[1]) 
        return board

