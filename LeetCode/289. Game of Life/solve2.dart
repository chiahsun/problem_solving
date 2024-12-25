class Solution {
  void gameOfLife(List<List<int>> board) {
    final M = board.length, N = board.first.length;
    List<List<int>> flips = [];
    int getAdjs(int x, int y) {
        int res = 0;
        final List<List<int>> dd = [[1, 0], [1, 1], [0, 1], [-1, 1],
          [-1, 0], [-1, -1], [0, -1], [1, -1]];
        for (final [dx, dy] in dd) {
            final nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (board[nx][ny] == 1) ++res;
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


    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (board[i][k] != nextState(i, k))
                flips.add([i, k]);
        }
    }
    for (final [i, k] in flips) {
        board[i][k] = 1 - board[i][k];
    }
  }
}
