class Solution {
  bool exist(List<List<String>> board, String word) {
    final M = board.length, N = board.first.length;
    final visited = List<List<bool>>.generate(M, (i) => List<bool>.generate(N, (k) => false, growable: false), growable: false);
    bool backtracking(int x, int y, int pos) {
        if (board[x][y] != word[pos]) return false;
        if (pos+1 >= word.length) return true;
        visited[x][y] = true;
        final dd = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        for (final [dx, dy] in dd) {
            final nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && backtracking(nx, ny, pos+1))
                return true;
        }
        visited[x][y] = false;
        return false;
    }

    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (backtracking(i, k, 0)) return true;
        }
    }
    return false;
  }
}
