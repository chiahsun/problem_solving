class Solution {
  int snakesAndLadders(List<List<int>> board) {
    final N = board.length, T = N*N;
    int getX(int v) { return N-(v-1)~/N-1; }
    int getY(int v) { return ((N - getX(v)) % 2 == 1) ? ((v-1) % N) : (N - (v-1) % N - 1);}
    List<int> q = [1], nextQ = [];
    int step = 0;
    while (!q.isEmpty) {
        while (!q.isEmpty) {
            final last = q.last; q.removeLast();
            for (int i = last+1; i < last+7; ++i) {
                final x = getX(i), y = getY(i);
                if (board[x][y] != 0) {
                    if (board[x][y] == -1) {
                        if (i == T) return step+1;
                        nextQ.add(i);
                    } else {
                        if (board[x][y] == T) return step+1;
                        nextQ.add(board[x][y]);
                    }
                    board[x][y] = 0;
                }
            }
        }
        q = nextQ; nextQ = []; ++step;
    }
    return -1;
  }
}

