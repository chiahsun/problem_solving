
class Solution {
  void solve(List<List<String>> board) {
    final M = board.length, N = board[0].length;
    final dx = [0, 0, 1, -1], dy = [1, -1, 0, 0];
    void dfs(x, y) {
        board[x][y] = 'V';
        for (int i = 0; i < 4; ++i) {
            final nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] == 'O')
                dfs(nx, ny);
        }
    }
    for (int i = 0; i < M; ++i) {
        if (board[i][0] == 'O') dfs(i, 0);
        if (board[i][N-1] == 'O') dfs(i, N-1);
    }
    for (int k = 0; k < N; ++k) {
        if (board[0][k] == 'O') dfs(0, k);
        if (board[M-1][k] == 'O') dfs(M-1, k);
    }
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (board[i][k] == 'V')
                board[i][k] = 'O';
            else if (board[i][k] == 'O')
                board[i][k] = 'X';
        }
    }
  }
}
