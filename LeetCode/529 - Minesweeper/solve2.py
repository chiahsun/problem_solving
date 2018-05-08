class Solution:
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        NROW, NCOL = len(board), len(board[0])
        
        def iterate_adj(r, c, fn):
            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    if dx != 0 or dy != 0:
                        x, y = r+dx, c+dy
                        if 0 <= x < NROW and 0 <= y < NCOL:
                            fn(x, y)
                            
        def dfs(r, c):
            if board[r][c] == 'M':
                board[r][c] = 'X'
            elif board[r][c] == 'E':
                n_adj_mines = 0
                
                def count_mine(x, y):
                    nonlocal n_adj_mines
                    if board[x][y] == 'M': n_adj_mines += 1
                        
                iterate_adj(r, c, count_mine)

                def dfs_empty(x, y):
                    if board[x][y] == 'E': dfs(x, y)
                        
                if n_adj_mines != 0:
                    board[r][c] = str(n_adj_mines)
                else:
                    board[r][c] = 'B'
                    iterate_adj(r, c, dfs_empty)
                    
        dfs(click[0], click[1]) 
        return board

