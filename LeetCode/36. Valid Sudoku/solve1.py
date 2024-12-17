class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def toggled(s, c):
            if c in s:
                return True
            if c != '.':
                s.append(c)
            return False
            
        l = len(board)
        for i in range(l):
            s = []
            for k in range(l):
                if toggled(s, board[i][k]):
                    return False
        for i in range(l):
            s = []
            for k in range(l):
                if toggled(s, board[k][i]):
                    return False
        for i in range(0, l, 3):
            for k in range(0, l, 3):
                s = []
                for x in range(3):
                    for y in range(3):
                        if toggled(s, board[i+x][k+y]):
                            return False
        return True       
