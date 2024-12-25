class Solution {
  void gameOfLife(List<List<int>> board) {
    final M = board.length, N = board.first.length;
    // https://stackoverflow.com/questions/69340832/in-dart-how-can-copy-clone-a-2d-list
    List<List<int>> curBoard = [ for(final l in board) [...l] ];
    // print(curBoard);
    int getAdjs(int x, int y) {
        int res = 0;
        final List<List<int>> dd = [[1, 0], [1, 1], [0, 1], [-1, 1],
          [-1, 0], [-1, -1], [0, -1], [1, -1]];
        for (final [dx, dy] in dd) {
            final nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (curBoard[nx][ny] == 1) ++res;
            }
        }
        return res;
    }

    int nextState(int x, int y) {
        final adjs = getAdjs(x, y);
        if (board[x][y] == 1) {
            if (adjs == 2 || adjs == 3) return 1;
        } else {
            if (adjs == 3) return 1;
        }
        return 0;
    }


    for (int i = 0; i < M; ++i)
        for (int k = 0; k < N; ++k)
            board[i][k] = nextState(i, k);
  }
}
